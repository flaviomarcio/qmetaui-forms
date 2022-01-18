#include "mu_form_link.h"

MUFormLinkItem::MUFormLinkItem(QObject *parent):MUFormLinkItemBase(parent)
{
}

QVariantHash MUFormLinkItem::header()const
{
    return MUFormLinkItemBase::header();
}

MUFormLinkItem&MUFormLinkItem::setHeader(const QVariant&value)
{
    MUFormLinkItemBase::setHeader(value);
    return*this;
}

QVariant MUFormLinkItem::method() const
{
    return MUFormLinkItemBase::method();
}

MUFormLinkItem &MUFormLinkItem::setMethod(const QVariant &value)
{
    MUFormLinkItemBase::setMethod(value);
    return*this;
}

QVariant MUFormLinkItem::ref() const
{
    return MUFormLinkItemBase::ref();
}

MUFormLinkItem &MUFormLinkItem::setRef(const QVariant &value)
{
    MUFormLinkItemBase::setRef(value);
    return*this;
}

QVariant MUFormLinkItem::hRef() const
{
    return MUFormLinkItemBase::hRef();
}

MUFormLinkItem &MUFormLinkItem::setHRef(const QVariant &value)
{
    MUFormLinkItemBase::setHRef(value);
    return*this;
}

QVariant MUFormLinkItem::parameters() const
{
    return MUFormLinkItemBase::parameters();
}

MUFormLinkItem &MUFormLinkItem::setParameters(const QVariant &value)
{
    MUFormLinkItemBase::setParameters(value);
    return*this;
}
