#pragma once


#include "./private/mu_form_link_base.h"

template <class T>
//!
//! \brief The MUFormLinkItem class
//!
class MUFormLinkItem : public PrivateQMetaUiForm::MUFormLinkItem{
public:
    Q_INVOKABLE explicit MUFormLinkItem(QObject*dtoParent, QObject*parent=nullptr):PrivateQMetaUiForm::MUFormLinkItem(dtoParent, parent)
    {
    }
    virtual ~MUFormLinkItem()
    {
    }
    virtual T&d()
    {
        auto object=&PrivateQMetaUiForm::MUFormLinkItem::d();
        return*dynamic_cast<T*>(object);
    }

    QVariantHash&header()
    {
        return PrivateQMetaUiForm::MUFormLinkItem::header();
    }

    auto&header(const QVariant&value)
    {
        PrivateQMetaUiForm::MUFormLinkItem::setHeader(value);
        return*this;
    }

    QVariant&method()
    {
        return PrivateQMetaUiForm::MUFormLinkItem::method();
    }

    auto&method(const QVariant&value)
    {
        PrivateQMetaUiForm::MUFormLinkItem::setMethod(value);
        return*this;
    }

    auto&setMethod(const QVariant&value)
    {
        PrivateQMetaUiForm::MUFormLinkItem::setMethod(value);
        return*this;
    }

    QVariant&ref()
    {
        return PrivateQMetaUiForm::MUFormLinkItem::ref();
    }

    auto&ref(const QVariant&value)
    {
        PrivateQMetaUiForm::MUFormLinkItem::setRef(value);
        return*this;
    }

    auto&setRef(const QVariant&value)
    {
        PrivateQMetaUiForm::MUFormLinkItem::setRef(value);
        return*this;
    }

    QVariant&hRef()
    {
        return PrivateQMetaUiForm::MUFormLinkItem::hRef();
    }

    auto&hRef(const QVariant&value)
    {
        PrivateQMetaUiForm::MUFormLinkItem::setHRef(value);
        return*this;
    }

    auto&setHRef(const QVariant&value)
    {
        PrivateQMetaUiForm::MUFormLinkItem::setHRef(value);
        return*this;
    }

    QVariant&parameters()
    {
        return PrivateQMetaUiForm::MUFormLinkItem::parameters();
    }

    auto&parameters(const QVariant&value)
    {
        PrivateQMetaUiForm::MUFormLinkItem::setParameters(value);
        return*this;
    }

    auto&setParameters(const QVariant&value)
    {
        PrivateQMetaUiForm::MUFormLinkItem::setParameters(value);
        return*this;
    }
};
