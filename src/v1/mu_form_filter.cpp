#include "./mu_form_filter.h"

MUFormFilter::MUFormFilter(QObject *parent):QStm::Object(parent)
{
}

QVariant MUFormFilter::type() const
{
    return this->v.value(qsl("type"));
}

MUFormFilter &MUFormFilter::setType(const QVariant &type)
{
    this->v.insert(qsl("type"),type);
    return*this;
}

QByteArray MUFormFilter::value() const
{
    return this->v.value(qsl("value")).toByteArray();
}

MUFormFilter &MUFormFilter::setValue(const QVariant &value)
{
    this->v.insert(qsl("value"), value);
    return*this;
}

QString MUFormFilter::defaultValue() const
{
    return this->v.value(qsl("defaultValue")).toByteArray();
}

MUFormFilter &MUFormFilter::setDefaultValue(const QVariant &value)
{
    this->v.insert(qsl("defaultValue"), value.toByteArray());
    return*this;
}

QString MUFormFilter::comboValue() const
{
    return this->v.value(qsl("comboValue")).toByteArray();
}

MUFormFilter &MUFormFilter::setComboValue(const QVariant &value)
{
    this->v.insert(qsl("comboValue"), value.toByteArray());
    return*this;
}

QString MUFormFilter::text() const
{
    return this->v.value(qsl("text")).toByteArray();
}

MUFormFilter &MUFormFilter::setText(const QVariant &value)
{
    this->v.insert(qsl("text"), value.toByteArray());
    return*this;
}

QVariant MUFormFilter::align() const
{
    return this->v.value(qsl("align"));
}

MUFormFilter &MUFormFilter::setAlign(const QVariant &value)
{
    this->v.insert(qsl("align"), value);
    return*this;
}

QVariant MUFormFilter::width() const
{
    return this->v.value(qsl("width")).toBool();
}

MUFormFilter &MUFormFilter::setWidth(const QVariant &value)
{
    this->v.insert(qsl("width"), value);
    return*this;
}

bool MUFormFilter::sortable() const
{
    return this->v.value(qsl("sortable")).toBool();
}

MUFormFilter &MUFormFilter::setSortable(const QVariant &value)
{
    this->v.insert(qsl("sortable"), value);
    return*this;
}

bool MUFormFilter::filtrable() const
{
    return this->v.value(qsl("filtrable")).toBool();
}

MUFormFilter &MUFormFilter::setFiltrable(const QVariant &value)
{
    this->v.insert(qsl("filtrable"), value);
    return*this;
}

MUFormFilterStyle MUFormFilter::filterStyle() const
{
    return MUFormFilterStyle(this->v.value(qsl("filterStyle")).toInt());
}

MUFormFilter &MUFormFilter::setFilterStyle(const QVariant &value)
{
    this->v.insert(qsl("filterStyle"), value);
    return*this;
}

QVariant MUFormFilter::toVariant() const
{
    return this->v;
}
