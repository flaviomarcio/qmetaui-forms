#pragma once

#include "./mu_form_link.h"

//!
//! \brief The MUFormLinks class
//!
class Q_QMETAUI_FORM_EXPORT MUFormLinks:public MUFormLinkCollectionBase{
    Q_OBJECT
public:
    //!
    //! \brief MUFormLinks
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormLinks(QObject*parent=nullptr);

    //!
    //! \brief ref
    //! \param ref
    //! \return
    //!
    virtual MUFormLinkItem&ref(const QVariant&ref);
};
