#include "./mu_form_control_cache.h"
#include <QMetaUi/Core>
#include <QMutex>

Q_GLOBAL_STATIC(QMutex, mutexEngine)

#define dPvt()\
auto&p = *reinterpret_cast<MUFormControlCachePvt*>(this->p)

class MUFormControlCachePvt:public QObject{
public:
    MUFormControlCache*parent=nullptr;
    QQmlComponent component;
    QQuickItem*quickParent=nullptr;
    QQuickItem*quickItem=nullptr;
    QQmlApplicationEngine&engine=MUApplication::engine();
    QString sourceMain, sourcePath;

    explicit MUFormControlCachePvt(MUFormControlCache*parent):QObject(parent), component(&MUApplication::engine())
    {
        this->parent=parent;
        QObject::connect(&this->component, &QQmlComponent::statusChanged, this, &MUFormControlCachePvt::quickItemStatus);
    }

    virtual ~MUFormControlCachePvt()
    {
        QMutexLocker locker(mutexEngine);
        auto importPathList=this->engine.importPathList();
        importPathList.removeOne(this->sourcePath);
        this->engine.setImportPathList(importPathList);
    }

public slots:

    void quickParentDestroy()
    {
        this->quickParent=nullptr;
        this->quickItem=nullptr;
    }

    void quickItemPrepare()
    {
        if(mutexEngine!=nullptr){//scope
            QMutexLocker locker(mutexEngine);//lock scope
            auto importPathList=this->engine.importPathList();
            if(importPathList.contains(this->sourceMain))
                importPathList.removeOne(this->sourcePath);
            this->engine.addImportPath(this->sourcePath);
        }
        auto mainFile=qsl("%1/%2").arg(this->sourcePath, this->sourceMain).simplified();
        auto url=QUrl::fromLocalFile(qsl("file://%1").arg(mainFile));
        this->component.loadUrl(url, QQmlComponent::PreferSynchronous);//async next step: quickItemStatus(...)
    }

    void quickItemStatus(QQmlComponent::Status status)
    {
        switch (status) {
        case QQmlComponent::Ready:
        {
            this->quickItemCreate();
            break;
        }
        case QQmlComponent::Error:
        {
            emit this->parent->error(QString(), this->component.errorString());
            emit parent->finished();
            break;
        }
        default:
            break;
        }
    }

    void quickItemCreate()
    {

        if(!this->component.isReady()){
            emit this->parent->error(QString(), qsl("QQmlComponent is not ready"));
            emit parent->finished();
            return;
        }

        auto qmlItemObject = component.create();
        if(qmlItemObject==nullptr)
            return;

        this->quickItem=dynamic_cast<QQuickItem*>(qmlItemObject);

        if(this->quickItem==nullptr){
            emit this->parent->error(QString(), qsl("Invalid create quickItemObject"));
            return;
        }

        this->quickItemConnect();
        emit parent->loaded();
        emit parent->finished();
    }

    void quickItemDestroy()
    {
        if(this->quickItem==nullptr)
            return;

        QObject::disconnect(this->quickItem, &QQuickItem::destroyed, this, &MUFormControlCachePvt::quickItemDestroyed);
        quickItem->deleteLater();
        this->quickItem=nullptr;
    }

    void quickItemDestroyed()
    {
        this->quickItem=nullptr;
    }

    void quickItemConnect()
    {
        QObject::connect(this->quickItem, &QQuickItem::destroyed, this, &MUFormControlCachePvt::quickItemDestroyed);
    }

private slots:
};

MUFormControlCache::MUFormControlCache(QObject *parent) : QObject(parent)
{
    this->p=new MUFormControlCachePvt(this);
}

bool MUFormControlCache::start()
{
    return true;
}

bool MUFormControlCache::cancel()
{
    return true;
}

QQuickItem *MUFormControlCache::quickParent() const
{
    dPvt();
    return p.quickParent;
}

void MUFormControlCache::setQuickParent(QQuickItem *newQuickParent)
{
    dPvt();
    if (p.quickParent == newQuickParent)
        return;

    if(p.quickParent!=nullptr)
        QObject::disconnect(p.quickParent, &QQuickItem::destroyed, &p, &MUFormControlCachePvt::quickParentDestroy);

    p.quickParent = newQuickParent;
    QObject::connect(p.quickParent, &QQuickItem::destroyed, &p, &MUFormControlCachePvt::quickParentDestroy);
    emit quickParentChanged();
}

void MUFormControlCache::resetQuickParent()
{
    this->setQuickParent({}); // TODO: Adapt to use your actual default value
}

QQuickItem *MUFormControlCache::quickItem() const
{
    dPvt();
    return p.quickItem;
}

void MUFormControlCache::setQuickItem(QQuickItem *newQuickItem)
{
    dPvt();
    if(newQuickItem==nullptr)
        p.quickItemDestroy();

    if (p.quickItem == newQuickItem)
        return;

    p.quickItemDestroy();
    p.quickItem=newQuickItem;
    p.quickItemConnect();
    emit quickItemChanged();
}

void MUFormControlCache::resetQuickItem()
{
    this->setQuickItem({});
}
