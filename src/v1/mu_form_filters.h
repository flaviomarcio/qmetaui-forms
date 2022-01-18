#pragma once

#include "./mu_form_filter.h"

//!
//! \brief The MUFormFilters class
//!
class Q_QMETAUI_FORM_EXPORT MUFormFilters:public QStm::Object{
    Q_OBJECT
public:

    explicit MUFormFilters(QObject*parent=nullptr):QStm::Object(parent)
    {
    }

    ~MUFormFilters()
    {
    }

    virtual QVariant toVar()const
    {
        QVariantList vList;
        for(const auto&v:this->___objectList)
            vList<<v->toVariant();
        return vList;
    };

    virtual MUFormFilter&value(const QString&v)
    {
        return this->value(QVariantHash{{vpType,v}});
    }

    virtual MUFormFilter&value(const QVariantHash&v)
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

    virtual MUFormFilters&clear()
    {
        this->___objectList.clear();
        return*this;
    }

    virtual QList<MUFormFilter*>&list()
    {
        return this->___objectList;
    }

private:
    QList<MUFormFilter*> ___objectList;
};
