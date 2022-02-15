#include "./mu_form_types.h"
#include "./mu_form_controls.h"
#include <QVariantHash>

static const QVariantHash __makeMUFormWindowType()
{
    QVariantHash ___return=
        {
            {QString::number(dftNormalForm), QString(QT_STRINGIFY2(NormalForm)).toLower()},
            {QString::number(dftAddressForm), QString(QT_STRINGIFY2(AddressForm)).toLower()},
            {QString(QT_STRINGIFY2(dftNormalForm)).toLower(), QString::number(dftNormalForm)},
            {QString(QT_STRINGIFY2(dftAddressForm)).toLower(), QString::number(dftAddressForm)},
            {QString(QT_STRINGIFY2(dftReportForm)).toLower(), QString::number(dftReportForm)},
            {QString(QT_STRINGIFY2(NormalForm)).toLower(), QString::number(dftNormalForm)},
            {QString(QT_STRINGIFY2(AddressForm)).toLower(), QString::number(dftAddressForm)},
            {QString(QT_STRINGIFY2(ReportForm)).toLower(), QString::number(dftReportForm)}
        };
    return ___return;
}

static const QVariantHash __makeMUFormLayout()
{
    QVariantHash ___return=
        {
            {QString::number(dflVerticalControls), QString(QT_STRINGIFY2(VerticalControls)).toLower()},
            {QString::number(dflHorizontalControls), QString(QT_STRINGIFY2(HorizontalControls)).toLower()},
            {QString(QT_STRINGIFY2(cfVerticalControls)).toLower(), QString::number(dflVerticalControls)},
            {QString(QT_STRINGIFY2(cfHorizontalControls)).toLower(), QString::number(dflHorizontalControls)},
            {QString(QT_STRINGIFY2(VerticalControls)).toLower(), QString::number(dflVerticalControls)},
            {QString(QT_STRINGIFY2(HorizontalControls)).toLower(), QString::number(dflHorizontalControls)}
        };
    return ___return;
}

static const auto __MUFormWindowTypeHash = __makeMUFormWindowType();
static const auto __MUFormLayoutHash = __makeMUFormLayout();

#define dPvt()\
auto&p = *reinterpret_cast<MUFormControlsPvt*>(this->p)

class MUFormControlsPvt{
public:
    QString resource;
    QString text;
    QVariant type=__MUFormWindowTypeHash.key(dftReportForm);
    QVariant layout=__MUFormLayoutHash.key(dflVerticalControls);
    QVariantHash sort;
    QString settingName;
    MUFormOutPutStyle outPutStyle=opsRowObject;
    MUFormHeaders headers;
    MUFormFilters filters;
    MUFormLinks links;
    MUFormCrud crud;
    MUFormItems items;
    QStm::ResultInfo resultInfo;
    MUFormControls*parent=nullptr;

    explicit MUFormControlsPvt(MUFormControls*parent)
        :
        headers(parent),
        filters(parent),
        links(parent),
        crud(parent),
        items(parent),
        resultInfo(parent)
    {
        this->parent=parent;
    }

    virtual ~MUFormControlsPvt()
    {
    }

//    QVariantHash toOutput()
//    {
//        QVariantHash vHash;
//        {//rows
//            QVector<QString> cacheHeader;

//            this->headers.makeDefault();
//            const auto&vHeaderList=this->headers.list();
//            const auto vFilter=this->filters.toVar().toList();
//            const auto vLinks=this->links.toVar().toList();
//            auto vItems=this->items.toVar().toList();

//            auto&vList=this->items.list();
//            if(vList.isEmpty()){
//                QVariantMap vRecord;
//                for(const auto&header:vHeaderList){
//                    auto headerName=header->value();
//                    vRecord[headerName]=QVariant();
//                }
//                vList<<vRecord;
//            }

//            for(auto&v:vList){
//                const auto vMap=v.toHash();
//                for(const auto&header:vHeaderList){
//                    auto headerName=header->value();
//                    if(vMap.contains(headerName))
//                        cacheHeader<<headerName;
//                }
//                break;
//            }

//            if(this->outPutStyle==opsRowArray){
//                QVariantList arItems;
//                for(auto&v:this->items.list()){
//                    const auto vMap=v.toHash();
//                    QVariantList aRow;
//                    for(auto&headerName:cacheHeader){
//                        auto value=vMap.value(headerName);
//                        aRow<<value;
//                    }
//                    if(!aRow.isEmpty())
//                        arItems<<aRow;
//                }
//                vHash.insert(vpItems, vItems );
//                vItems=arItems;
//            }



//            auto vHeader=QVariantList();
//            for(const auto&header:vHeaderList){
//                auto headerName=header->value();
//                auto var=header->toVar();

//                if(headerName==vActions)
//                    vHeader<<var;
//                else if(cacheHeader.contains(headerName))//se o cachec contiver a header entao lancaremos
//                    vHeader<<var;

//            }

//            vHash[vpId]=this->id;
//            vHash[vpText]=this->text;
//            vHash[vpType]=this->type;
//            vHash[vpLayout]=this->layout;
//            vHash[vpHeaders]=vHeader;
//            vHash[vpFilters]=vFilter;
//            vHash[vpItems]=vItems;
//            vHash[vpLinks]=vLinks;
//            vHash[vpResultInfo]=this->resultInfo.toHash();

//            {
//                Q_V_HASH_ITERATOR(this->sort){
//                    i.next();
//                    vHash[i.key()]=i.value();
//                }
//            }

//        }
//        return vHash;
//    }

    void setFileName(const QString&fileName)
    {
        QFile file(fileName);
        if(!file.exists())
            return;

        if(!file.open(file.ReadOnly))
            return;

        auto v=QJsonDocument::fromJson(file.readAll()).toVariant();
        file.close();
        this->setSettings(v);
    }


    void setSettings(const QVariant&value)
    {
        auto vHash=value.toHash();

        if(vHash.isEmpty())
            return;

        QVariantHash v;
        auto resource=this->resource.toLower().trimmed();
        if(vHash.contains(qsl("id")))
            v=vHash;
        else if(!resource.isEmpty() || vHash.contains(resource))
            v=vHash.value(resource).toHash();
        else if(vHash.contains(qsl_null) || vHash.contains(vpDefault)){
            v=vHash.value(vpDefault).toHash();
            if(v.isEmpty())
                v=vHash.value(qsl_null).toHash();
        }

        if(v.isEmpty())
            return;

        this->headers.fromVar(v.value(vpHeaders));
        this->filters.fromVar(v.value(vpFilters));
        this->items.fromVar(v.value(vpItems));
    }

    void clear()
    {
        this->headers.clear();
        this->filters.clear();
        this->items.clear();
        this->resultInfo.clear();
    }
};

MUFormControls::MUFormControls(QObject *parent) : QStm::Object(parent)
{
    this->p = new MUFormControlsPvt(this);
}

MUFormControls::~MUFormControls()
{
    dPvt();
    delete&p;
}

QStm::ResultInfo &MUFormControls::resultInfo()
{
    dPvt();
    return p.resultInfo;
}

MUFormControls &MUFormControls::setResultInfo(const QStm::ResultInfo &resultInfo)
{
    dPvt();
    p.resultInfo.fromHash(resultInfo.toHash());
    return*this;
}

QString MUFormControls::resource() const
{
    dPvt();
    return p.resource;
}

MUFormControls &MUFormControls::setResource(const QVariant&v)
{
    dPvt();
    p.resource=v.toString();
    return*this;
}

QVariant MUFormControls::type() const
{
    dPvt();
    const auto&map=__MUFormWindowTypeHash;
    auto value=p.type;
    switch (qTypeId(value)) {
    case QMetaType_LongLong:
        return map[QString::number(value.toLongLong())];
    default:
        return map.value(value.toString().toLower());
    }
}

MUFormControls &MUFormControls::setType(const QVariant &v)
{
    dPvt();
    p.type=v.toString();
    return*this;
}

QVariant MUFormControls::layout() const
{
    dPvt();
    const auto&map=__MUFormLayoutHash;
    auto value=p.layout;
    switch (qTypeId(value)) {
    case QMetaType_Int:
    case QMetaType_UInt:
    case QMetaType_LongLong:
    case QMetaType_ULongLong:
        return map.value(QString::number(value.toLongLong()));
    default:
        return map.value(value.toString().toLower());
    }
}

MUFormControls &MUFormControls::setLayout(const QVariant &v)
{
    dPvt();
    p.layout=v.toString();
    return*this;
}

QVariantHash MUFormControls::sort() const
{
    dPvt();
    return p.sort;
}

MUFormControls &MUFormControls::setSort(const QVariant &v)
{
    dPvt();
    p.sort=v.toHash();
    return*this;
}

QString MUFormControls::text() const
{
    dPvt();
    return p.text;
}

MUFormControls &MUFormControls::setText(const QVariant &v)
{
    dPvt();
    p.text=v.toString();
    return*this;
}

MUFormOutPutStyle&MUFormControls::outPutStyle() const
{
    dPvt();
    return p.outPutStyle;
}

MUFormControls &MUFormControls::setOutPutStyle(const MUFormOutPutStyle &value)
{
    dPvt();
    p.outPutStyle = value;
    return*this;
}

MUFormHeaders &MUFormControls::headers()
{
    dPvt();
    return p.headers;
}

MUFormFilters &MUFormControls::filters()
{
    dPvt();
    return p.filters;
}

MUFormLinks &MUFormControls::links()
{
    dPvt();
    return p.links;
}

MUFormCrud &MUFormControls::crud()
{
    dPvt();
    return p.crud;
}

MUFormItems &MUFormControls::items()
{
    dPvt();
    return p.items;
}

MUFormControls &MUFormControls::setItems(const QVariant &v)
{
    dPvt();
    p.items.fromVar(v);
    return*this;
}

MUFormControls &MUFormControls::setItems(const ResultValue &lr)
{
    dPvt();
    p.items.fromVar(this->lr(lr).resultVariant());
    return*this;
}

MUFormControls &MUFormControls::setValue(const QVariant &v)
{
    dPvt();
    p.items.fromVar(v);
    return*this;
}

MUFormControls &MUFormControls::setValue(const ResultValue &lr)
{
    dPvt();
    p.items.fromVar(this->lr(lr).resultVariant());
    return*this;
}

MUFormControls &MUFormControls::setSettings(const QVariant &setting)
{
    dPvt();
    p.setSettings(setting);
    return*this;
}

MUFormControls &MUFormControls::setFileName(const QString &fileName)
{
    dPvt();
    p.setFileName(fileName);
    return*this;
}

MUFormControls &MUFormControls::clear()
{
    dPvt();
    p.clear();
    return*this;
}
