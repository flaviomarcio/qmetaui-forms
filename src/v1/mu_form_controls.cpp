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

static const QVariantHash __makeDTOFormLayout()
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

static const auto __MUFormWindowTypeMap = __makeMUFormWindowType();
static const auto __DTOFormLayoutMap = __makeDTOFormLayout();

#define dPvt()\
auto&p = *reinterpret_cast<MUFormControlsPvt*>(this->p)

class MUFormControlsPvt{
public:
    QString id;
    QString text;
    QVariant type=__MUFormWindowTypeMap.key(dftReportForm);
    QVariant layout=__DTOFormLayoutMap.key(dflVerticalControls);
    QVariantHash sort;
    QString settingName;
    MUFormOutPutStyle outPutStyle=opsRowObject;
    MUFormHeaders<MUFormControls> headers;
    MUFormFilters<MUFormControls> filters;
    MUFormLinks<MUFormControls> links;
    MUFormCrud<MUFormControls> crud;
    MUFormItems<MUFormControls> items;
    QStm::ResultInfo resultInfo;
    QObject*dto=nullptr;

    explicit MUFormControlsPvt(MUFormControls*parent)
        :
        headers(parent, parent),
        filters(parent, parent),
        links(parent, parent),
        crud(parent, parent),
        items(parent,parent),
        resultInfo(parent)
    {
        this->dto=parent;
    }

    virtual ~MUFormControlsPvt()
    {
    }

    QVariantHash toOutput()
    {
        QVariantHash vHash;
        {//rows
            QVector<QString> cacheHeader;

            this->headers.makeDefault();
            const auto&vHeaderList=this->headers.list();
            const auto vFilter=this->filters.toVar().toList();
            const auto vLinks=this->links.toVar().toList();
            auto vItems=this->items.toVar().toList();

            auto&vList=this->items.list();
            if(vList.isEmpty()){
                QVariantMap vRecord;
                for(const auto&header:vHeaderList){
                    auto headerName=header->value();
                    vRecord[headerName]=QVariant();
                }
                vList<<vRecord;
            }

            for(auto&v:vList){
                const auto vMap=v.toHash();
                for(const auto&header:vHeaderList){
                    auto headerName=header->value();
                    if(vMap.contains(headerName))
                        cacheHeader<<headerName;
                }
                break;
            }

            if(this->outPutStyle==opsRowArray){
                QVariantList arItems;
                for(auto&v:this->items.list()){
                    const auto vMap=v.toHash();
                    QVariantList aRow;
                    for(auto&headerName:cacheHeader){
                        auto value=vMap.value(headerName);
                        aRow<<value;
                    }
                    if(!aRow.isEmpty())
                        arItems<<aRow;
                }
                vHash.insert(vpItems, vItems );
                vItems=arItems;
            }



            auto vHeader=QVariantList();
            for(const auto&header:vHeaderList){
                auto headerName=header->value();
                auto var=header->toVar();

                if(headerName==vActions)
                    vHeader<<var;
                else if(cacheHeader.contains(headerName))//se o cachec contiver a header entao lancaremos
                    vHeader<<var;

            }

            vHash[vpId]=this->id;
            vHash[vpText]=this->text;
            vHash[vpType]=this->type;
            vHash[vpLayout]=this->layout;
            vHash[vpHeaders]=vHeader;
            vHash[vpFilters]=vFilter;
            vHash[vpItems]=vItems;
            vHash[vpLinks]=vLinks;
            vHash[vpResultInfo]=this->resultInfo.toHash();

            {
                Q_V_HASH_ITERATOR(this->sort){
                    i.next();
                    vHash[i.key()]=i.value();
                }
            }

        }
        return vHash;
    }


    void setSettings(const QVariant&value)
    {
        auto dtoMap=value.toHash();
        QVariantHash v;
        if(!dtoMap.isEmpty()){
            auto id=this->id.toLower().trimmed();
            if(!id.isEmpty() || dtoMap.contains(id)){
                v=dtoMap.value(id).toHash();
            }
            else if(dtoMap.contains(qsl_null) || dtoMap.contains(vpDefault)){
                v=dtoMap.value(vpDefault).toHash();
                if(v.isEmpty())
                    v=dtoMap.value(qsl_null).toHash();
            }
        }

        if(!v.isEmpty()){
            this->headers.fromHash(v.value(vpHeaders).toHash());
            this->filters.fromHash(v.value(vpFilters).toHash());
            this->items.fromList(v.value(vpItems));
        }
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

QString MUFormControls::id() const
{
    dPvt();
    return p.id;
}

MUFormControls &MUFormControls::id(const QVariant&v)
{
    dPvt();
    p.id=v.toString();
    return*this;
}

QVariant MUFormControls::type() const
{
    dPvt();
    const auto&map=__MUFormWindowTypeMap;
    auto value=p.type;
    switch (qTypeId(value)) {
    case QMetaType_LongLong:
        return map[QString::number(value.toLongLong())];
    default:
        return map.value(value.toString().toLower());
    }
}

MUFormControls &MUFormControls::type(const QVariant &v)
{
    dPvt();
    p.type=v.toString();
    return*this;
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
    const auto&map=__DTOFormLayoutMap;
    auto value=p.layout;
    switch (qTypeId(value)) {
    case QMetaType_LongLong:
        return map.value(QString::number(value.toLongLong()));
    default:
        return map.value(value.toString().toLower());
    }
}

MUFormControls &MUFormControls::layout(const QVariant &v)
{
    dPvt();
    p.layout=v.toString();
    return*this;
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

MUFormControls &MUFormControls::sort(const QVariant &v)
{
    dPvt();
    p.sort=v.toHash();
    return*this;
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

MUFormControls &MUFormControls::text(const QVariant &v)
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

MUFormControls &MUFormControls::outPutStyle(const MUFormOutPutStyle &value)
{
    dPvt();
    p.outPutStyle = value;
    return*this;
}

MUFormControls &MUFormControls::setOutPutStyle(const MUFormOutPutStyle &value)
{
    dPvt();
    p.outPutStyle = value;
    return*this;
}

MUFormControls &MUFormControls::settings(const QVariant &setting)
{
    dPvt();
    p.setSettings(setting);
    return*this;
}

MUFormHeaders<MUFormControls> &MUFormControls::headers()
{
    dPvt();
    return p.headers;
}

MUFormFilters<MUFormControls> &MUFormControls::filters()
{
    dPvt();
    return p.filters;
}

MUFormLinks<MUFormControls> &MUFormControls::links()
{
    dPvt();
    return p.links;
}

MUFormCrud<MUFormControls> &MUFormControls::crud()
{
    dPvt();
    return p.crud;
}

MUFormItems<MUFormControls> &MUFormControls::items()
{
    dPvt();
    return p.items;
}

MUFormControls &MUFormControls::items(const QVariant &v)
{
    dPvt();
    p.items.fromList(v);
    return*this;
}

MUFormControls &MUFormControls::items(const ResultValue &lr)
{
    dPvt();
    p.items.fromList(this->lr(lr).resultVariant());
    return*this;
}

MUFormControls &MUFormControls::setValue(const QVariant &v)
{
    dPvt();
    p.items.fromList(v);
    return*this;
}

MUFormControls &MUFormControls::setValue(const ResultValue &lr)
{
    dPvt();
    p.items.fromList(this->lr(lr).resultVariant());
    return*this;
}

MUFormControls &MUFormControls::clear()
{
    dPvt();
    p.clear();
    return*this;
}

ResultValue &MUFormControls::o()
{
    dPvt();
    return this->lr(p.toOutput());
}

ResultValue &MUFormControls::toOutput()
{
    dPvt();
    return this->lr(p.toOutput());
}
