#pragma once

#include "./private/p_mu_form_link_base.h"

//!
//! \brief The MUFormCrudItem class
//!
class Q_QMETAUI_FORM_EXPORT MUFormCrudItem : public QStm::Object{
    Q_OBJECT
public:
    Q_INVOKABLE explicit MUFormCrudItem(QObject*parent=nullptr);
    ~MUFormCrudItem();

    //!
    //! \brief item
    //! \return
    //!
    const MUFormLinkItemBase &item() const;
    MUFormCrudItem&setItem(const MUFormLinkItemBase &newItem);

private:
    void*p=nullptr;
};

//!
//! \brief The MUFormCrud class
//!
class Q_QMETAUI_FORM_EXPORT MUFormCrud:public MUFormLinkCollectionBase{
    Q_OBJECT
public:
    //!
    //! \brief MUFormCrud
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormCrud(QObject*parent=nullptr);

    //!
    //! \brief item
    //! \return
    //!
    const MUFormLinkItemBase &item() const;
    MUFormCrudItem&setItem(const MUFormLinkItemBase &newItem);
};
