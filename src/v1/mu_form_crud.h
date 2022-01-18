#pragma once

#include "./private/mu_form_link_base.h"


template <class T>
//!
//! \brief The MUFormCrudItem class
//!
class MUFormCrudItem : public QStm::Object{
public:
    Q_INVOKABLE explicit MUFormCrudItem(QObject*dtoParent, QObject*parent=nullptr):QStm::Object(parent), item(dtoParent, parent)
    {
    }
    virtual T&d()
    {
        auto object=&this->item.d();
        return*dynamic_cast<T*>(object);
    }
    PrivateQMetaUiForm::MUFormLinkItem item;
};

template <class T>
//!
//! \brief The MUFormCrud class
//!
class MUFormCrud:public PrivateQMetaUiForm::MUFormLinkCollection
{
public:
    explicit MUFormCrud(QObject*dtoParent, QObject*parent=nullptr):PrivateQMetaUiForm::MUFormLinkCollection(dtoParent, parent)
    {
    }
    virtual T&d()
    {
        auto object=&PrivateQMetaUiForm::MUFormLinkCollection::d();
        return*dynamic_cast<T*>(object);
    }
};
