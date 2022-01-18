#pragma once

#include "./private/p_mu_form_link_base.h"

//!
//! \brief The MUFormLinkItem class
//!
class Q_QMETAUI_FORM_EXPORT MUFormLinkItem : public MUFormLinkItemBase{
    Q_OBJECT
public:
    Q_INVOKABLE explicit MUFormLinkItem(QObject*parent=nullptr):MUFormLinkItemBase(parent)
    {
    }

    QVariantHash&header()
    {
        return MUFormLinkItemBase::header();
    }

    auto&header(const QVariant&value)
    {
        MUFormLinkItemBase::setHeader(value);
        return*this;
    }

    QVariant&method()
    {
        return MUFormLinkItemBase::method();
    }

    auto&method(const QVariant&value)
    {
        MUFormLinkItemBase::setMethod(value);
        return*this;
    }

    auto&setMethod(const QVariant&value)
    {
        MUFormLinkItemBase::setMethod(value);
        return*this;
    }

    QVariant&ref()
    {
        return MUFormLinkItemBase::ref();
    }

    auto&ref(const QVariant&value)
    {
        MUFormLinkItemBase::setRef(value);
        return*this;
    }

    auto&setRef(const QVariant&value)
    {
        MUFormLinkItemBase::setRef(value);
        return*this;
    }

    QVariant&hRef()
    {
        return MUFormLinkItemBase::hRef();
    }

    auto&hRef(const QVariant&value)
    {
        MUFormLinkItemBase::setHRef(value);
        return*this;
    }

    auto&setHRef(const QVariant&value)
    {
        MUFormLinkItemBase::setHRef(value);
        return*this;
    }

    QVariant&parameters()
    {
        return MUFormLinkItemBase::parameters();
    }

    auto&parameters(const QVariant&value)
    {
        MUFormLinkItemBase::setParameters(value);
        return*this;
    }

    auto&setParameters(const QVariant&value)
    {
        MUFormLinkItemBase::setParameters(value);
        return*this;
    }
};
