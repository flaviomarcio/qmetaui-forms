#include "mu_form_header.h"

MUFormHeader::MUFormHeader(QObject *parent):QStm::Object(parent)
{
}

MUFormHeader*MUFormHeader::makeFrom(QObject *parent, const QVariantHash &vHash)
{
    auto __return=new MUFormHeader(parent);
    if(!__return->fromHash(vHash)){
        delete __return;
        return nullptr;
    }
    return __return;
}

QVariant MUFormHeader::order() const
{
    return QVariant(this->v.value(vpOrder).toInt());
}

MUFormHeader &MUFormHeader::setOrder(const QVariant &order)
{
    this->v.insert(vpOrder,order.toInt());
    return*this;
}

QVariant MUFormHeader::type() const
{
    return QVariant(this->v.value(vpType));
}

MUFormHeader &MUFormHeader::setType(const QVariant &type)
{
    this->v.insert(vpType,type);
    return*this;
}

QString MUFormHeader::value() const
{
    return this->v.value(vpValue).toByteArray();
}

MUFormHeader &MUFormHeader::setValue(const QVariant &value)
{
    this->v.insert(vpValue, value.toByteArray());
    return*this;
}

QString MUFormHeader::defaultValue() const
{
    return this->v.value(vpDefaultValue).toByteArray();
}

MUFormHeader &MUFormHeader::setDefaultValue(const QVariant &value)
{
    this->v.insert(vpDefaultValue, value.toByteArray());
    return*this;
}

QVariant MUFormHeader::defaultSelect() const
{
    return this->v.value(vpDefaultSelect);
}

MUFormHeader &MUFormHeader::setDefaultSelect(const QVariant &value)
{
    this->v.insert(vpDefaultSelect, value);
    return*this;
}

QString MUFormHeader::text() const
{
    return this->v.value(vpText).toByteArray();
}

MUFormHeader &MUFormHeader::setText(const QVariant &value)
{
    this->v.insert(vpText, value.toByteArray());
    return*this;
}

QVariant MUFormHeader::align() const
{
    return this->v.value(vpAlign);
}

MUFormHeader &MUFormHeader::setAlign(const QVariant &value)
{
    this->v.insert(vpAlign, value);
    return*this;
}

QVariant MUFormHeader::width() const
{
    return this->v.value(vpWidth).toBool();
}

MUFormHeader &MUFormHeader::setWidth(const QVariant &value)
{
    this->v.insert(vpWidth, value);
    return*this;
}

QVariant MUFormHeader::inputType() const
{
    return this->v.value(vpInputType);
}

MUFormHeader &MUFormHeader::setInputType(const QVariant &value)
{
    this->v.insert(vpInputType, value);
    return*this;
}

QVariant MUFormHeader::inputMask() const
{
    return this->v.value(vpInputType);
}

MUFormHeader &MUFormHeader::setInputMask(const QVariant &value)
{
    this->v.insert(vpInputMask, value);
    return*this;
}

QVariant MUFormHeader::inputLinks() const
{
    return this->v.value(vtInputLinks);
}

MUFormHeader &MUFormHeader::setInputLinks(const QVariant &value)
{
    this->v.insert(vtInputLinks, value);
    return*this;
}

QVariant MUFormHeader::length() const
{
    return this->v.value(vpLength);
}

MUFormHeader &MUFormHeader::setLength(const QVariant &value)
{
    this->v.insert(vpLength, value.toInt());
    return*this;
}

bool MUFormHeader::visible() const
{
    return this->v.value(vpVisible).toBool();
}

MUFormHeader &MUFormHeader::setVisible(const QVariant &value)
{
    auto v=(value.isNull() || !value.isValid())?true:value.toBool();
    this->v.insert(vpVisible, v);
    return*this;
}

bool MUFormHeader::readOnly() const
{
    return this->v.value(vpReadOnly).toBool();
}

MUFormHeader &MUFormHeader::setReadOnly(const QVariant &value)
{
    auto v=(value.isNull() || !value.isValid())?true:value.toBool();
    this->v.insert(vpReadOnly, v);
    return*this;
}

bool MUFormHeader::editable() const
{
    return this->v.value(vpEditable).toBool();
}

MUFormHeader &MUFormHeader::setEditable(const QVariant &value)
{
    this->v.insert(vpEditable, value.toBool());
    return*this;
}

bool MUFormHeader::sortable() const
{
    return this->v.value(vpSortable).toBool();
}

MUFormHeader &MUFormHeader::setSortable(const QVariant &value)
{
    this->v.insert(vpSortable, value.toBool());
    return*this;
}

bool MUFormHeader::filtrable() const
{
    return this->v.value(vpFiltrable).toBool();
}

MUFormHeader &MUFormHeader::setFiltrable(const QVariant &value)
{
    this->v.insert(vpFiltrable, value.toBool());
    return*this;
}

QVariantHash MUFormHeader::filtrableStrategy() const
{
    return this->v.value(vpFiltrableStrategy).toHash();
}

MUFormHeader &MUFormHeader::setFiltrableStrategy(const QVariant &value)
{
    this->v.insert(vpFiltrableStrategy, value);
    return*this;
}

MUFormFilterStyle MUFormHeader::filterStyle() const
{
    return MUFormFilterStyle(this->v.value(vpFilterStyle).toInt());
}

MUFormHeader &MUFormHeader::setFilterStyle(const QVariant &value)
{
    this->v.insert(vpFilterStyle, value.toInt());
    return*this;
}
