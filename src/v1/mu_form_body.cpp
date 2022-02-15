#include "./mu_form_body.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

Q_GLOBAL_STATIC(QVariantHash, MUFormServerSettings)

static void initMUFormServerSettingsCache()
{
    QVariantHash __MUFormServerSettings;
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
        case QMetaType_QVariantMap:
        case QMetaType_QVariantList:
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
                __MUFormServerSettings.insert(i.key(), i.value());
            }
        }
    }
    *MUFormServerSettings=__MUFormServerSettings;
}

Q_COREAPP_STARTUP_FUNCTION(initMUFormServerSettingsCache)


#define dPvt()\
auto&p = *reinterpret_cast<MUFormBodyPvt*>(this->p)

class Q_QMETAUI_FORM_EXPORT MUFormBodyPvt{
public:
    MUFormControls muFormControls;

    MUFormBody*parent=nullptr;

    explicit MUFormBodyPvt(MUFormBody*parent)
    {
        this->parent=parent;
    }

    virtual ~MUFormBodyPvt()
    {
    }

    void initObjects()
    {
        const auto className=QString::fromUtf8(this->parent->parent()->metaObject()->className()).toLower().trimmed();
        auto settings=MUFormServerSettings->value(className).toHash();
        this->muFormControls.setSettings(settings);
    }

    void clear()
    {
        this->muFormControls.clear();
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
    p.muFormControls.setValue(rows.resultVariant());
}

MUFormBody::~MUFormBody()
{
    dPvt();
    delete&p;
}

MUFormBody &MUFormBody::operator=(const MUFormBody &v)
{
    Q_UNUSED(v)
    return*this;
}

QString MUFormBody::resource() const
{
    dPvt();
    return p.muFormControls.resource();
}

MUFormBody &MUFormBody::setResource(const QVariant &value)
{
    dPvt();
    p.muFormControls.setResource(value);
    return*this;
}

QVariant MUFormBody::type() const
{
    dPvt();
    auto value=p.muFormControls.type();
    if(value.isNull() && !value.isValid()){
        value=this->defaultType();
    }
    return value;
}

MUFormBody &MUFormBody::setType(const QVariant &v)
{
    dPvt();
    p.muFormControls.setType(v);
    return*this;
}

QVariant MUFormBody::layout() const
{
    dPvt();
    auto value=p.muFormControls.layout();
    if(value.isNull() && !value.isValid())
        return this->defaultLayout();
    return value;
}

MUFormBody &MUFormBody::setLayout(const QVariant &v)
{
    dPvt();
    p.muFormControls.setLayout(v);
    return*this;
}

MUFormControls &MUFormBody::controls()
{
    dPvt();
    return p.muFormControls;
}

MUFormHeaders &MUFormBody::headers()
{
    dPvt();
    return p.muFormControls.headers();
}

MUFormFilters &MUFormBody::filters()
{
    dPvt();
    return p.muFormControls.filters();
}

MUFormLinks &MUFormBody::links()
{
    dPvt();
    return p.muFormControls.links();
}

MUFormItems &MUFormBody::items()
{
    dPvt();
    return p.muFormControls.items();
}

MUFormControls &MUFormBody::setItems(const QVariant &v)
{
    dPvt();
    return p.muFormControls.setItems(v);
}

MUFormControls &MUFormBody::setItems(const ResultValue &lr)
{
    dPvt();
    return p.muFormControls.setItems(lr.resultVariant());
}

QStm::ResultInfo &MUFormBody::resultInfo()
{
    dPvt();
    return p.muFormControls.resultInfo();
}

MUFormControls &MUFormBody::setResultInfo(const QStm::ResultInfo &resultInfo)
{
    dPvt();
    p.muFormControls.resultInfo().fromHash(resultInfo.toHash());
    return p.muFormControls;
}

MUFormBody &MUFormBody::setValue(const QVariant &v)
{
    dPvt();
    p.muFormControls.setItems(v);
    return*this;
}

QString MUFormBody::text() const
{
    dPvt();
    return p.muFormControls.text();
}

MUFormBody &MUFormBody::setText(const QVariant &v)
{
    dPvt();
    p.muFormControls.setText(v);
    return*this;
}

QVariantHash MUFormBody::sort() const
{
    dPvt();
    return p.muFormControls.sort();
}

MUFormBody &MUFormBody::setSort(const QVariant &v)
{
    dPvt();
    p.muFormControls.setSort(v);
    return*this;
}

MUFormBody &MUFormBody::setValue(const ResultValue &lr)
{
    dPvt();
    p.muFormControls.setValue(lr.resultVariant());
    return*this;
}

MUFormBody &MUFormBody::setSettings(const QVariant &setting)
{
    dPvt();
    p.muFormControls.setSettings(setting.toHash());
    return*this;
}

MUFormBody &MUFormBody::setFileName(const QString &fileName)
{
    dPvt();
    p.muFormControls.setFileName(fileName);
    return*this;
}

MUFormBody &MUFormBody::clear()
{
    dPvt();
    p.clear();
    return*this;
}

