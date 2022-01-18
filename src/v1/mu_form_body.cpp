#include "mu_form_body.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

Q_GLOBAL_STATIC(QVariantHash, dtoSettings)

#define dPvt()\
auto&p = *reinterpret_cast<MUFormBodyPvt*>(this->p)

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
    *dtoSettings=__dtoSettings;
}

Q_COREAPP_STARTUP_FUNCTION(initDtoSettingsCache)


class Q_QMETAUI_FORM_EXPORT MUFormBodyPvt{
public:
    MUFormControls dtoControls;

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
        auto settings=dtoSettings->value(className).toHash();
        this->dtoControls.setSettings(settings);
    }

    void clear()
    {
        this->dtoControls.clear();
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

MUFormBody &MUFormBody::setType(const QVariant &v)
{
    dPvt();
    p.dtoControls.setType(v);
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

MUFormBody &MUFormBody::setLayout(const QVariant &v)
{
    dPvt();
    p.dtoControls.setLayout(v);
    return*this;
}

MUFormControls &MUFormBody::controls()
{
    dPvt();
    return p.dtoControls;
}

MUFormHeaders &MUFormBody::headers()
{
    dPvt();
    return p.dtoControls.headers();
}

MUFormFilters &MUFormBody::filters()
{
    dPvt();
    return p.dtoControls.filters();
}

MUFormLinks &MUFormBody::links()
{
    dPvt();
    return p.dtoControls.links();
}

MUFormItems &MUFormBody::items()
{
    dPvt();
    return p.dtoControls.items();
}

MUFormControls &MUFormBody::setItems(const QVariant &v)
{
    dPvt();
    return p.dtoControls.setItems(v);
}

MUFormControls &MUFormBody::setItems(const ResultValue &lr)
{
    dPvt();
    return p.dtoControls.setItems(lr.resultVariant());
}

QStm::ResultInfo &MUFormBody::resultInfo()
{
    dPvt();
    return p.dtoControls.resultInfo();
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
    p.dtoControls.setItems(v);
    return*this;
}

QString MUFormBody::text() const
{
    dPvt();
    return p.dtoControls.text();
}

MUFormBody &MUFormBody::setText(const QVariant &v)
{
    dPvt();
    p.dtoControls.setText(v);
    return*this;
}

QVariantHash MUFormBody::sort() const
{
    dPvt();
    return p.dtoControls.sort();
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

MUFormBody &MUFormBody::setSettings(const QVariant &setting)
{
    dPvt();
    p.dtoControls.setSettings(setting.toHash());
    return*this;
}

MUFormBody &MUFormBody::clear()
{
    dPvt();
    p.clear();
    return*this;
}

