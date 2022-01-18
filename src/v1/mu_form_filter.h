#pragma once

#include <QMetaUi/Core>
#include "./mu_form_global.h"
#include "./mu_form_types.h"

//!
//! \brief The MUFormFilter class
//!
class Q_QMETAUI_FORM_EXPORT MUFormFilter : public QStm::Object{
    Q_OBJECT
public:

    Q_PROPERTY(QVariant     type            READ type           WRITE setType            )
    Q_PROPERTY(QVariant     value           READ value          WRITE setValue           )
    Q_PROPERTY(QVariant     defaultValue    READ defaultValue   WRITE setDefaultValue    )
    Q_PROPERTY(QVariant     comboValue      READ comboValue     WRITE setComboValue      )
    Q_PROPERTY(QVariant     text            READ text           WRITE setText            )
    Q_PROPERTY(QVariant     align           READ align          WRITE setAlign           )
    Q_PROPERTY(QVariant     width           READ width          WRITE setWidth           )
    Q_PROPERTY(bool         sortable        READ sortable       WRITE setSortable        )
    Q_PROPERTY(bool         filtrable       READ filtrable      WRITE setFiltrable       )
    Q_PROPERTY(QVariant     filterStyle     READ filterStyle    WRITE setFilterStyle     )

    Q_INVOKABLE explicit MUFormFilter(QObject*parent=nullptr):QStm::Object(parent)
    {
    }

    ~MUFormFilter()
    {

    }

    virtual QVariant type() const
    {
        return this->v.value(qsl("type"));
    }

    virtual MUFormFilter&type(const QVariant &type)
    {
        return this->setType(type);
    }

    virtual MUFormFilter&setType(const QVariant &type)
    {
        this->v.insert(qsl("type"),type);
        return*this;
    }

    virtual QByteArray value() const
    {
        return this->v.value(qsl("value")).toByteArray();
    }

    virtual MUFormFilter&value(const QVariant &value)
    {
        return this->setValue(value);
    }

    virtual MUFormFilter&setValue(const QVariant &value)
    {
        this->v.insert(qsl("value"), value);
        return*this;
    }

    virtual QString defaultValue() const
    {
        return this->v.value(qsl("defaultValue")).toByteArray();
    }

    virtual MUFormFilter&defaultValue(const QVariant &value)
    {
        return this->setDefaultValue(value);
    }

    virtual MUFormFilter&setDefaultValue(const QVariant &value)
    {
        this->v.insert(qsl("defaultValue"), value.toByteArray());
        return*this;
    }

    virtual QString comboValue() const
    {
        return this->v.value(qsl("comboValue")).toByteArray();
    }

    virtual MUFormFilter&comboValue(const QVariant &value)
    {
        return this->setComboValue(value);
    }

    virtual MUFormFilter&setComboValue(const QVariant &value)
    {
        this->v.insert(qsl("comboValue"), value.toByteArray());
        return*this;
    }

    virtual QString text() const
    {
        return this->v.value(qsl("text")).toByteArray();
    }

    virtual MUFormFilter&text(const QVariant &value)
    {
        return this->setText(value);
    }

    virtual MUFormFilter&setText(const QVariant &value)
    {
        this->v.insert(qsl("text"), value.toByteArray());
        return*this;
    }

    virtual QVariant align() const
    {
        return this->v.value(qsl("align"));
    }

    virtual MUFormFilter&align(const QVariant& value)
    {
        return this->setAlign(value);
    }

    virtual MUFormFilter&setAlign(const QVariant& value)
    {
        this->v.insert(qsl("align"), value);
        return*this;
    }

    virtual QVariant width() const
    {
        return this->v.value(qsl("width")).toBool();
    }

    virtual MUFormFilter&width(const QVariant& value)
    {
        return this->setWidth(value);
    }

    virtual MUFormFilter&setWidth(const QVariant& value)
    {
        this->v.insert(qsl("width"), value);
        return*this;
    }

    virtual bool sortable() const
    {
        return this->v.value(qsl("sortable")).toBool();
    }

    virtual MUFormFilter&sortable(const QVariant &value)
    {
        return this->setSortable(value);
    }

    virtual MUFormFilter&setSortable(const QVariant &value)
    {
        this->v.insert(qsl("sortable"), value);
        return*this;
    }

    virtual bool filtrable() const
    {
        return this->v.value(qsl("filtrable")).toBool();
    }

    virtual MUFormFilter&filtrable(const QVariant &value)
    {
        return this->setFiltrable(value);
    }

    virtual MUFormFilter&setFiltrable(const QVariant &value)
    {
        this->v.insert(qsl("filtrable"), value);
        return*this;
    }

    virtual MUFormFilterStyle filterStyle() const
    {
        return MUFormFilterStyle(this->v.value(qsl("filterStyle")).toInt());
    }

    virtual MUFormFilter&filterStyle(const MUFormFilterStyle &value)
    {
        return this->setFilterStyle(value);
    }

    virtual MUFormFilter&setFilterStyle(const QVariant &value)
    {
        this->v.insert(qsl("filterStyle"), value);
        return*this;
    }

    virtual QVariant toVariant()const
    {
        return this->v;
    };

private:
    QVariantHash v;
};
