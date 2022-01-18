#include "mu_form_body.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

namespace PrivateQMetaUiForm {
Q_GLOBAL_STATIC(QVariantHash, dtoSettings)
}

#define dPvt()\
auto&p = *reinterpret_cast<MUFormBodyPvt*>(this->p)

static auto&dtoSettings=*PrivateQMetaUiForm::dtoSettings;

static void initDtoSettingsCache()
{
    QVariantHash __dtoSettings;
    QDir dir(qsl(":"));
    dir.setNameFilters(QStringList{qsl("settings.qmeta.forms.json")});
    for(auto&info:dir.entryInfoList()){
        QFile fileSrc(info.filePath());
        if(!fileSrc.open(fileSrc.ReadOnly))
#if Q_ORM_LOG
            sWarning()<<qsl("No open file:")<<fileSrc.fileName()<<qsl(", error: ")<<fileSrc.errorString();
#endif
        continue;

        auto bytes=fileSrc.readAll();
        fileSrc.close();
        QVariantList vList;
        auto vDoc=QJsonDocument::fromJson(bytes).toVariant();
        switch (qTypeId(vDoc)) {
        case QMetaType_QVariantHash:
            vList<<vDoc;
            break;
        case QMetaType_QVariantMap:
            vList<<vDoc;
            break;
        case QMetaType_QVariantList:
            vList<<vDoc;
            break;
        case QMetaType_QStringList:
            vList<<vDoc;
            break;
        default:
            break;
        }
        for(auto&v:vList){
            auto vDoc=v.toHash();
            QHashIterator<QString, QVariant> i(vDoc);
            while (i.hasNext()) {
                i.next();
                __dtoSettings.insert(i.key(), i.value());
            }
        }
    }
    dtoSettings=__dtoSettings;
}

Q_COREAPP_STARTUP_FUNCTION(initDtoSettingsCache)


class MUFormBodyPvt{
public:
    MUFormControls dtoControls;

    QObject*dto=nullptr;

    explicit MUFormBodyPvt(MUFormBody*parent)
    {
        this->dto=parent;
        auto pParent=parent->parent();
        if(pParent!=nullptr)
            this->initDescriptors(pParent);
    }

    virtual ~MUFormBodyPvt()
    {
    }

    void initObjects(){
        const auto className=QString::fromUtf8(this->dto->parent()->metaObject()->className()).toLower().trimmed();
        auto settings=dtoSettings.value(className).toHash();
        this->dtoControls.settings(settings);
    }

    void clear(){
        this->dtoControls.clear();
    }

    void initDescriptors(QObject*)
    {
//        auto model=dynamic_cast<Model*>(object);
//        if(model==nullptr)
//            return;
//        const auto&modelInfo=ModelInfo::modelInfo(model->metaObject()->className());
//        const auto&descriptors=modelInfo.propertyDescriptors();
//        this->dtoControls.headers().clear().makeDefault();
//        for(auto&v:descriptors){
//            this->dtoControls.headers().value(v.toHash());
//        }
    }
};

MUFormBody::MUFormBody(QObject *parent) : QStm::Object(parent)
{
    this->p = new MUFormBodyPvt(this);
}

MUFormBody::MUFormBody(const ResultValue &rows, QObject *parent) : QStm::Object(parent)
{
    this->p = new MUFormBodyPvt(this);
    dPvt();
    p.dtoControls.setValue(rows.resultVariant());
}

MUFormBody::~MUFormBody()
{
    dPvt();
    delete&p;
}

QString MUFormBody::id() const
{
    dPvt();
    return p.dtoControls.id();
}

MUFormBody &MUFormBody::id(const QVariant &v)
{
    dPvt();
    p.dtoControls.id(v);
    return*this;
}

MUFormBody &MUFormBody::setId(const QVariant &value)
{
    dPvt();
    p.dtoControls.id(value);
    return*this;
}

QVariant MUFormBody::type() const
{
    dPvt();
    auto value=p.dtoControls.type();
    if(value.isNull() && !value.isValid()){
        value=this->defaultType();
    }
    return value;
}

MUFormBody &MUFormBody::type(const QVariant &v)
{
    dPvt();
    p.dtoControls.type(v);
    return*this;
}

MUFormBody &MUFormBody::setType(const QVariant &v)
{
    dPvt();
    p.dtoControls.type(v);
    return*this;
}

QVariant MUFormBody::layout() const
{
    dPvt();
    auto value=p.dtoControls.layout();
    if(value.isNull() && !value.isValid())
        return this->defaultLayout();
    return value;
}

MUFormBody &MUFormBody::layout(const QVariant &v)
{
    dPvt();
    p.dtoControls.layout(v);
    return*this;
}

MUFormBody &MUFormBody::setLayout(const QVariant &v)
{
    dPvt();
    p.dtoControls.layout(v);
    return*this;
}

MUFormBody &MUFormBody::settings(const QVariant &setting)
{
    dPvt();
    p.dtoControls.settings(setting.toHash());
    return*this;
}

MUFormControls &MUFormBody::controls()
{
    dPvt();
    return p.dtoControls;
}

MUFormHeaders<MUFormControls> &MUFormBody::headers()
{
    dPvt();
    return p.dtoControls.headers();
}

MUFormFilters<MUFormControls> &MUFormBody::filters()
{
    dPvt();
    return p.dtoControls.filters();
}

MUFormLinks<MUFormControls> &MUFormBody::links()
{
    dPvt();
    return p.dtoControls.links();
}

MUFormItems<MUFormControls> &MUFormBody::items()
{
    dPvt();
    return p.dtoControls.items();
}

MUFormControls &MUFormBody::items(const QVariant &v)
{
    dPvt();
    return p.dtoControls.items(v);
}

MUFormControls &MUFormBody::items(const ResultValue &lr)
{
    dPvt();
    return p.dtoControls.items(lr.resultVariant());
}

QStm::ResultInfo &MUFormBody::resultInfo()
{
    dPvt();
    return p.dtoControls.resultInfo();
}

MUFormControls &MUFormBody::resultInfo(const QVariant &v)
{
    dPvt();
    p.dtoControls.resultInfo().fromVar(v);
    return p.dtoControls;
}

MUFormControls &MUFormBody::setResultInfo(const QStm::ResultInfo &resultInfo)
{
    dPvt();
    p.dtoControls.resultInfo().fromHash(resultInfo.toHash());
    return p.dtoControls;
}

MUFormBody &MUFormBody::setValue(const QVariant &v)
{
    dPvt();
    p.dtoControls.items(v);
    return*this;
}

QString MUFormBody::text() const
{
    dPvt();
    return p.dtoControls.text();
}

MUFormBody &MUFormBody::text(const QVariant &v)
{
    dPvt();
    p.dtoControls.text(v);
    return*this;
}

MUFormBody &MUFormBody::setText(const QVariant &v)
{
    dPvt();
    p.dtoControls.text(v);
    return*this;
}

QVariantHash MUFormBody::sort() const
{
    dPvt();
    return p.dtoControls.sort();
}

MUFormBody &MUFormBody::sort(const QVariant &v)
{
    dPvt();
    p.dtoControls.sort(v);
    return*this;
}

MUFormBody &MUFormBody::setSort(const QVariant &v)
{
    dPvt();
    p.dtoControls.setSort(v);
    return*this;
}

MUFormBody &MUFormBody::setValue(const ResultValue &lr)
{
    dPvt();
    p.dtoControls.setValue(lr.resultVariant());
    return*this;
}

MUFormBody &MUFormBody::clear()
{
    dPvt();
    p.clear();
    return*this;
}

ResultValue &MUFormBody::o()
{
    dPvt();
    return p.dtoControls.o();
}

ResultValue &MUFormBody::toOutput()
{
    dPvt();
    return p.dtoControls.o();
}

MUFormBody &MUFormBody::initDescriptors(QObject *object)
{
    dPvt();
    p.initDescriptors(object);
    return*this;
}
