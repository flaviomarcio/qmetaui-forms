#pragma once

#include <QMetaUi/Core>
#include "./mu_form_global.h"
#include "./mu_form_types.h"

template <class T>
//!
//! \brief The MUFormItems class
//!
class MUFormItems:public QStm::Object
{
public:
    explicit MUFormItems(QObject*parent=nullptr):QStm::Object(parent)
    {
    }

    explicit MUFormItems(QObject*dtoParent, QObject*parent=nullptr):QStm::Object(parent)
    {
        this->___d=dtoParent;
    }

    virtual ~MUFormItems()
    {
    }

    template<class TD=T>
    TD&d()
    {
        return*dynamic_cast<T*>(this->___d);
    }

    virtual MUFormItems&clear()
    {
        this->___objectList.clear();
        return*this;
    }

    virtual MUFormItems&fromList(const QVariant&v)
    {
        this->___objectList=v.toList();
        return*this;
    }

    virtual QVariant toVar()const
    {
        return this->___objectList;
    };

    virtual QVariantList&list()
    {
        return this->___objectList;
    }

private:
    QObject*___d=nullptr;
    QVariantList ___objectList;
};
