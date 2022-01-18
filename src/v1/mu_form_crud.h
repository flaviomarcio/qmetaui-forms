#pragma once

#include "./private/p_mu_form_link_base.h"

//!
//! \brief The MUFormCrudItem class
//!
class Q_QMETAUI_FORM_EXPORT MUFormCrudItem : public QStm::Object{
    Q_OBJECT
public:
    Q_INVOKABLE explicit MUFormCrudItem(QObject*parent=nullptr):QStm::Object(parent), item(parent)
    {
    }
    MUFormLinkItemBase item;
};

//!
//! \brief The MUFormCrud class
//!
class Q_QMETAUI_FORM_EXPORT MUFormCrud:public MUFormLinkCollectionBase{
    Q_OBJECT
public:
    explicit MUFormCrud(QObject*parent=nullptr):MUFormLinkCollectionBase(parent)
    {
    }
};
