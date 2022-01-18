#pragma once

#include "./mu_form_filter.h"

template <class T>
//!
//! \brief The MUFormFilters class
//!
class MUFormFilters:public QStm::Object
{
public:

    explicit MUFormFilters(T*dto, QObject*parent=nullptr):QStm::Object(parent)
    {
        this->___d=dto;
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

    virtual T&d()
    {
        return*this->___d;
    }

    virtual MUFormFilter<T>&value(const QString&v)
    {
        return this->value(QVariantHash{{vpType,v}});
    }

    virtual MUFormFilter<T>&value(const QVariantHash&v)
    {
        auto object=new MUFormFilter<T>(this->___d, this);
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

    virtual MUFormFilters<T>&clear()
    {
        this->___objectList.clear();
        return*this;
    }

    virtual QList<MUFormFilter<T>*>&list()
    {
        return this->___objectList;
    }

private:
    T*___d=nullptr;
    QList<MUFormFilter<T>*> ___objectList;
};
