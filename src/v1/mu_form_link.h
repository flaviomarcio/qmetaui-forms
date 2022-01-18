#pragma once

#include "./private/p_mu_form_link_base.h"

//!
//! \brief The MUFormLinkItem class
//!
class Q_QMETAUI_FORM_EXPORT MUFormLinkItem : public MUFormLinkItemBase{
    Q_OBJECT
public:
    //!
    //! \brief MUFormLinkItem
    //! \param parent
    //!
    Q_INVOKABLE; explicit MUFormLinkItem(QObject*parent=nullptr);

    //!
    //! \brief header
    //! \return
    //!
    QVariantHash header()const;
    MUFormLinkItem&setHeader(const QVariant&value);

    //!
    //! \brief method
    //! \return
    //!
    QVariant method()const;
    MUFormLinkItem&setMethod(const QVariant&value);

    //!
    //! \brief ref
    //! \return
    //!
    QVariant ref()const;
    MUFormLinkItem&setRef(const QVariant&value);

    //!
    //! \brief hRef
    //! \return
    //!
    QVariant hRef()const;
    MUFormLinkItem&setHRef(const QVariant&value);

    //!
    //! \brief parameters
    //! \return
    //!
    QVariant parameters()const;
    MUFormLinkItem&setParameters(const QVariant&value);
};
