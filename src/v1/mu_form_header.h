#pragma once

#include <QMetaUi/Core>
#include "./mu_form_global.h"
#include "./mu_form_types.h"

template <class T>
//!
//! \brief The MUFormHeader class
//!
class MUFormHeader : public QStm::Object{

public:
    enum FilterStyle{
        dsAutoDectect=MUFormFilterStyle::fsAutoDectect
    };

    enum Alignment{
        Start=faStart, Center=faCenter, End=faEnd
    };

    Q_ENUM(FilterStyle)

    Q_PROPERTY(QVariant     order               READ order              WRITE setOrder              )
    Q_PROPERTY(QVariant     type                READ type               WRITE setType               )
    Q_PROPERTY(QVariant     value               READ value              WRITE setValue              )
    Q_PROPERTY(QVariant     defaultValue        READ defaultValue       WRITE setDefaultValue       )
    Q_PROPERTY(QVariant     text                READ text               WRITE setText               )
    Q_PROPERTY(QVariant     length              READ length             WRITE setLength             )
    Q_PROPERTY(Alignment    align               READ align              WRITE setAlign              )
    Q_PROPERTY(QVariant     width               READ width              WRITE setWidth              )
    Q_PROPERTY(bool         visible             READ visible            WRITE setVisible            )
    Q_PROPERTY(bool         editable            READ editable           WRITE setEditable           )
    Q_PROPERTY(bool         sortable            READ sortable           WRITE setSortable           )
    Q_PROPERTY(bool         filtrable           READ filtrable          WRITE setFiltrable          )
    Q_PROPERTY(QVariant     filterStyle         READ filterStyle        WRITE setFilterStyle        )
    Q_PROPERTY(QVariant     filtrableStrategy   READ filtrableStrategy  WRITE setFiltrableStrategy  )
    Q_PROPERTY(QVariant     readOnly            READ readOnly           WRITE setReadOnly           )
    Q_PROPERTY(QVariant     defaultValue        READ defaultValue       WRITE setDefaultValue       )
    Q_PROPERTY(QVariant     defaultSelect       READ defaultSelect      WRITE setDefaultSelect      )
    Q_PROPERTY(QVariant     inputType           READ inputType          WRITE setInputType          )
    Q_PROPERTY(QVariant     inputMask           READ inputMask          WRITE setInputMask          )
    Q_PROPERTY(QVariant     inputLinks          READ inputLinks         WRITE setInputLinks         )

    Q_INVOKABLE explicit MUFormHeader(T*dto, QObject*parent=nullptr):QStm::Object(parent){
        this->___d=dto;
    }

    Q_INVOKABLE virtual ~MUFormHeader(){

    }

    T&d(){
        return*this->___d;
    }

    virtual QVariant order() const
    {
        return QVariant(this->v.value(vpOrder).toInt());
    }

    virtual MUFormHeader&order(const QVariant &order)
    {
        return this->setOrder(order);
    }

    virtual MUFormHeader&setOrder(const QVariant &order)
    {
        this->v.insert(vpOrder,order.toInt());
        return*this;
    }

    virtual MUFormHeader&type(const QVariant &type)
    {
        return this->setType(type);
    }

    virtual MUFormHeader&setType(const QVariant &type)
    {
        this->v.insert(vpType,type);
        return*this;
    }

    virtual QString value() const
    {
        return this->v.value(vpValue).toByteArray();
    }

    virtual MUFormHeader&value(const QVariant &value)
    {
        return this->setValue(value);
    }

    virtual MUFormHeader&setValue(const QVariant &value)
    {
        this->v.insert(vpValue, value.toByteArray());
        return*this;
    }

    virtual QString defaultValue() const
    {
        return this->v.value(vpDefaultValue).toByteArray();
    }

    virtual MUFormHeader&defaultValue(const QVariant &value)
    {
        return this->setDefaultValue(value);
    }

    virtual MUFormHeader&setDefaultValue(const QVariant &value)
    {
        this->v.insert(vpDefaultValue, value.toByteArray());
        return*this;
    }

    virtual QVariant defaultSelect() const
    {
        return this->v.value(vpDefaultSelect);
    }

    virtual MUFormHeader&defaultSelect(const QVariant &value)
    {
        this->v.insert(vpDefaultSelect, value);
        return*this;
    }

    virtual QString text() const
    {
        return this->v.value(vpText).toByteArray();
    }

    virtual MUFormHeader&text(const QVariant &value)
    {
        return this->setText(value);
    }

    virtual MUFormHeader&setText(const QVariant &value)
    {
        this->v.insert(vpText, value.toByteArray());
        return*this;
    }

    virtual QVariant align() const
    {
        return this->v.value(vpAlign);
    }

    virtual MUFormHeader&align(const QVariant& value)
    {
        return this->setAlign(value);
    }

    virtual MUFormHeader&setAlign(const QVariant& value)
    {
        this->v.insert(vpAlign, value);
        return*this;
    }

    virtual QVariant width() const
    {
        return this->v.value(vpWidth).toBool();
    }

    virtual MUFormHeader&width(const QVariant& value)
    {
        return this->setWidth(value);
    }

    virtual MUFormHeader&setWidth(const QVariant& value)
    {
        this->v.insert(vpWidth, value);
        return*this;
    }

    virtual QVariant inputType() const
    {
        return this->v.value(vpInputType);
    }

    virtual MUFormHeader&inputType(const QVariant &value)
    {
        this->v.insert(vpInputType, value);
        return*this;
    }

    virtual QVariant inputMask() const
    {
        return this->v.value(vpInputType);
    }

    virtual MUFormHeader&inputMask(const QVariant &value)
    {
        this->v.insert(vpInputMask, value);
        return*this;
    }

    virtual QVariant inputLinks() const
    {
        return this->v.value(vtInputLinks);
    }

    virtual MUFormHeader&inputLinks(const QVariant &value)
    {
        this->v.insert(vtInputLinks, value);
        return*this;
    }

    virtual QVariant length() const
    {
        return this->v.value(vpLength);
    }

    virtual MUFormHeader&length(const QVariant &value)
    {
        this->v.insert(vpLength, value.toInt());
        return*this;
    }

    virtual bool visible() const
    {
        return this->v.value(vpVisible).toBool();
    }

    virtual MUFormHeader&visible(const QVariant&value)
    {
        return this->setVisible(value);
    }

    virtual MUFormHeader&setVisible(const QVariant&value)
    {
        auto v=(value.isNull() || !value.isValid())?true:value.toBool();
        this->v.insert(vpVisible, v);
        return*this;
    }

    virtual bool readOnly() const
    {
        return this->v.value(vpReadOnly).toBool();
    }

    virtual MUFormHeader&readOnly(const QVariant&value)
    {
        auto v=(value.isNull() || !value.isValid())?true:value.toBool();
        this->v.insert(vpReadOnly, v);
        return*this;
    }

    virtual bool editable() const
    {
        return this->v.value(vpEditable).toBool();
    }

    virtual MUFormHeader&editable(const QVariant&value)
    {
        return this->setEditable(value);
    }

    virtual MUFormHeader&setEditable(const QVariant&value)
    {
        this->v.insert(vpEditable, value.toBool());
        return*this;
    }

    virtual bool sortable() const
    {
        return this->v.value(vpSortable).toBool();
    }

    virtual MUFormHeader&sortable(const QVariant&value)
    {
        return this->setSortable(value);
    }

    virtual MUFormHeader&setSortable(const QVariant&value)
    {
        this->v.insert(vpSortable, value.toBool());
        return*this;
    }

    virtual bool filtrable() const
    {
        return this->v.value(vpFiltrable).toBool();
    }

    virtual MUFormHeader&filtrable(const QVariant&value)
    {
        return this->setFiltrable(value);
    }

    virtual MUFormHeader&setFiltrable(const QVariant&value)
    {
        this->v.insert(vpFiltrable, value.toBool());
        return*this;
    }

    virtual QVariantHash filtrableStrategy() const
    {
        return this->v.value(vpFiltrableStrategy).toHash();
    }

    virtual MUFormHeader&filtrableStrategy(const QVariant&value)
    {
        return this->setFiltrableStrategy(value);
    }

    virtual MUFormHeader&setFiltrableStrategy(const QVariant&value)
    {
        this->v.insert(vpFiltrableStrategy, value);
        return*this;
    }

    virtual MUFormFilterStyle filterStyle() const
    {
        return MUFormFilterStyle(this->v.value(vpFilterStyle).toInt());
    }

    virtual MUFormHeader&filterStyle(const QVariant &value)
    {
        return this->setFilterStyle(value);
    }

    virtual MUFormHeader&setFilterStyle(const QVariant &value)
    {
        this->v.insert(vpFilterStyle, value.toInt());
        return*this;
    }

    virtual QVariant toVar()const{
        return this->v;
    };

    virtual const QVariantHash&toHash(){
        return this->v;
    };

    virtual QVariantMap toMap()const {
        return QVariant(this->v).toMap();
    };

private:
    QVariantHash v;
    T*___d=nullptr;
};
