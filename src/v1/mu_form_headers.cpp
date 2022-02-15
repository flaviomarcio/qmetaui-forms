#include "./mu_form_headers.h"
#include "./mu_form_header.h"

#define dPvt()\
auto&p = *reinterpret_cast<MUFormHeadersPvt*>(this->p)

class MUFormHeadersPvt{
public:
    MUFormHeaders*parent=nullptr;
    QMap<QString, MUFormHeader*> ___objectMap;
    QList<MUFormHeader*> ___objectList;
    explicit MUFormHeadersPvt(MUFormHeaders*parent)
    {
        this->parent=parent;
    }

    virtual ~MUFormHeadersPvt()
    {
    }

    void clear()
    {
        qDeleteAll(this->___objectList);
        this->___objectMap.clear();
        this->___objectList.clear();
    }
};

MUFormHeaders::MUFormHeaders(QObject *parent):MUFormObjectModel(parent)
{
    this->p=new MUFormHeadersPvt(this);
}

MUFormHeaders::~MUFormHeaders()
{
    dPvt();
    delete&p;
}

const QMetaObject &MUFormHeaders::objectMetaObject()const
{
    return MUFormHeader::staticMetaObject;
}

void MUFormHeaders::clear()
{
    dPvt();
    p.clear();
    MUFormObjectModel::clear();
}

QVariant MUFormHeaders::toVar() const
{
    dPvt();
    QVariantList vList;
    for(auto&v:p.___objectList)
        vList<<v->toVar();
    return vList;
}

QVariant MUFormHeaders::toList() const
{
    dPvt();
    QVariantList vList;
    for(auto&v:p.___objectList)
        vList<<v->toVar();
    return vList;
}

MUFormHeader *MUFormHeaders::get(const QString &v)
{
    dPvt();
    return p.___objectMap.value(v);
}

MUFormHeaders &MUFormHeaders::remove(const QString &v)
{
    dPvt();
    if(p.___objectMap.contains(v)){
        auto object=p.___objectMap.take(v);
        p.___objectList.removeOne(object);
        delete object;
    }
    return*this;
}

MUFormHeader &MUFormHeaders::value(const QString &v)
{
    return this->value(QVariantHash{{vpValue,v}});
}

MUFormHeader &MUFormHeaders::value(const QVariantHash &v)
{
    dPvt();
    auto value=v.value(vpValue).toString();
    auto object=p.___objectMap.value(value);
    if(object==nullptr){
        object=new MUFormHeader(this);
        object->setOrder(p.___objectMap.count());
        p.___objectList<<object;
        p.___objectMap.insert(value, object);
    }
    object->setType(v.value(vpType));
    object->setValue(v.value(vpValue));
    object->setDefaultValue(v.value(vpDefaultValue));
    object->setDefaultSelect(v.value(vpDefaultSelect));
    object->setText(v.value(vpText));
    object->setAlign(v.value(vpAlign));
    object->setWidth(v.value(vpWidth));
    object->setVisible(v.value(vpVisible));
    object->setReadOnly(v.value(vpReadOnly));
    object->setEditable(v.value(vpEditable));
    object->setSortable(v.value(vpSortable));
    object->setLength(v.value(vpLength));
    object->setFiltrable(v.value(vpFiltrable));
    object->setFiltrableStrategy(v.value(vpFiltrableStrategy));
    object->setFilterStyle(v.value(vpFilterStyle));
    object->setInputType(v.value(vpInputType));
    object->setInputMask(v.value(vpInputMask));
    object->setInputLinks(v.value(vtInputLinks));
    return*object;
}

MUFormHeader &MUFormHeaders::makeDefault()
{
    static auto vAction=QVariantHash( { { vpValue, vpActions}, { vpText, qsl_null}, { vpSortable, false }, { vpVisible, true }, { vpWidth, qsl("0%") }});
    return this->value(vAction);
}

MUFormHeaders &MUFormHeaders::unMakeDefault()
{
    return this->remove(vpActions);
}

QList<MUFormHeader *> &MUFormHeaders::list()
{
    dPvt();
    this->reOrder();
    return p.___objectList;
}

void MUFormHeaders::reOrder()
{
    dPvt();
    auto i=0;
    for(auto&v:p.___objectList)
        v->setOrder(i++);
}
