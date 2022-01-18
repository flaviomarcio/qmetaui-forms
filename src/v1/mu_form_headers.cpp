#include "mu_form_headers.h"

MUFormHeaders::MUFormHeaders(QObject *parent):QStm::Object(parent)
{
}

MUFormHeaders &MUFormHeaders::clear()
{
    this->___objectMap.clear();
    this->___objectList.clear();
    return*this;
}

QVariant MUFormHeaders::toVar() const
{
    QVariantList vList;
    for(const auto&v:this->___objectList)
        vList<<v->toVar();
    return vList;
}

QVariant MUFormHeaders::toList() const
{
    QVariantList vList;
    for(const auto&v:this->___objectList)
        vList<<v->toVar();
    return vList;
}

MUFormHeader *MUFormHeaders::get(const QString &v)
{
    return this->___objectMap.value(v);
}

MUFormHeaders &MUFormHeaders::remove(const QString &v)
{
    if(this->___objectMap.contains(v)){
        auto object=this->___objectMap.take(v);
        this->___objectList.removeOne(object);
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
    auto value=v.value(vpValue).toString();
    auto object=this->___objectMap.value(value);
    if(object==nullptr){
        object=new MUFormHeader(this);
        object->setOrder(this->___objectMap.count());
        this->___objectList<<object;
        this->___objectMap.insert(value, object);
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
    this->reOrder();
    return this->___objectList;
}

void MUFormHeaders::reOrder()
{
    auto i=0;
    for(auto&v:this->___objectList)
        v->setOrder(i++);
}
