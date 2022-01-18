#include "mu_form_filters.h"

MUFormFilters::MUFormFilters(QObject *parent):QStm::Object(parent)
{
}

QVariant MUFormFilters::toVar() const
{
    QVariantList vList;
    for(const auto&v:this->___objectList)
        vList<<v->toVariant();
    return vList;
}

MUFormFilter &MUFormFilters::value(const QString &v)
{
    return this->setValue(QVariantHash{{vpType,v}});
}

MUFormFilter &MUFormFilters::setValue(const QVariantHash &v)
{
    auto object=new MUFormFilter(this);
    object->setType(v.value(vpType));
    object->setValue(v.value(vpValue));
    object->setDefaultValue(v.value(vpDefaultValue));
    object->setText(v.value(vpText));
    object->setAlign(v.value(vpAlign));
    object->setWidth(v.value(vpWidth));
    object->setSortable(v.value(vpSortable));
    object->setFiltrable(v.value(vpFiltrable));
    object->setFilterStyle(v.value(vpFilterStyle));
    this->___objectList<<object;
    return*object;
}

MUFormFilters &MUFormFilters::clear()
{
    this->___objectList.clear();
    return*this;
}

QList<MUFormFilter *> &MUFormFilters::list()
{
    return this->___objectList;
}
