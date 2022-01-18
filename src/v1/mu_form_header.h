#pragma once

#include <QMetaUi/Core>
#include "./mu_form_global.h"
#include "./mu_form_types.h"

//!
//! \brief The MUFormHeader class
//!
class Q_QMETAUI_FORM_EXPORT MUFormHeader : public QStm::Object{
    Q_OBJECT
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
    Q_PROPERTY(QVariant     align               READ align              WRITE setAlign              )
    Q_PROPERTY(QVariant     width               READ width              WRITE setWidth              )
    Q_PROPERTY(bool         visible             READ visible            WRITE setVisible            )
    Q_PROPERTY(bool         editable            READ editable           WRITE setEditable           )
    Q_PROPERTY(bool         sortable            READ sortable           WRITE setSortable           )
    Q_PROPERTY(bool         filtrable           READ filtrable          WRITE setFiltrable          )
    Q_PROPERTY(QVariant     filterStyle         READ filterStyle        WRITE setFilterStyle        )
    Q_PROPERTY(QVariant     filtrableStrategy   READ filtrableStrategy  WRITE setFiltrableStrategy  )
    Q_PROPERTY(QVariant     readOnly            READ readOnly           WRITE setReadOnly           )
    Q_PROPERTY(QVariant     defaultSelect       READ defaultSelect      WRITE setDefaultSelect      )
    Q_PROPERTY(QVariant     inputType           READ inputType          WRITE setInputType          )
    Q_PROPERTY(QVariant     inputMask           READ inputMask          WRITE setInputMask          )
    Q_PROPERTY(QVariant     inputLinks          READ inputLinks         WRITE setInputLinks         )

    Q_INVOKABLE explicit MUFormHeader(QObject*parent=nullptr);

    //!
    //! \brief order
    //! \return
    //!
    virtual QVariant order() const;
    virtual MUFormHeader&setOrder(const QVariant &order)
    {
        this->v.insert(vpOrder,order.toInt());
        return*this;
    }

    //!
    //! \brief type
    //! \return
    //!
    virtual QVariant type()const;
    virtual MUFormHeader&setType(const QVariant &type);

    //!
    //! \brief value
    //! \return
    //!
    virtual QString value() const;
    virtual MUFormHeader&setValue(const QVariant &value);

    //!
    //! \brief defaultValue
    //! \return
    //!
    virtual QString defaultValue() const;
    virtual MUFormHeader&setDefaultValue(const QVariant &value);

    //!
    //! \brief defaultSelect
    //! \return
    //!
    virtual QVariant defaultSelect() const;
    virtual MUFormHeader&setDefaultSelect(const QVariant &value);

    //!
    //! \brief text
    //! \return
    //!
    virtual QString text() const;
    virtual MUFormHeader&setText(const QVariant &value);

    //!
    //! \brief align
    //! \return
    //!
    virtual QVariant align() const;
    virtual MUFormHeader&setAlign(const QVariant& value);

    //!
    //! \brief width
    //! \return
    //!
    virtual QVariant width() const;
    virtual MUFormHeader&setWidth(const QVariant& value);

    //!
    //! \brief inputType
    //! \return
    //!
    virtual QVariant inputType() const;
    virtual MUFormHeader&setInputType(const QVariant &value);

    //!
    //! \brief inputMask
    //! \return
    //!
    virtual QVariant inputMask() const;
    virtual MUFormHeader&setInputMask(const QVariant &value);

    //!
    //! \brief inputLinks
    //! \return
    //!
    virtual QVariant inputLinks() const;
    virtual MUFormHeader&setInputLinks(const QVariant &value);

    //!
    //! \brief length
    //! \return
    //!
    virtual QVariant length() const;
    virtual MUFormHeader&setLength(const QVariant &value);

    //!
    //! \brief visible
    //! \return
    //!
    virtual bool visible() const;
    virtual MUFormHeader&setVisible(const QVariant&value);

    //!
    //! \brief readOnly
    //! \return
    //!
    virtual bool readOnly() const;
    virtual MUFormHeader&setReadOnly(const QVariant&value);

    //!
    //! \brief editable
    //! \return
    //!
    virtual bool editable() const;
    virtual MUFormHeader&setEditable(const QVariant&value);

    //!
    //! \brief sortable
    //! \return
    //!
    virtual bool sortable() const;
    virtual MUFormHeader&setSortable(const QVariant&value);

    //!
    //! \brief filtrable
    //! \return
    //!
    virtual bool filtrable() const;
    virtual MUFormHeader&setFiltrable(const QVariant&value);

    //!
    //! \brief filtrableStrategy
    //! \return
    //!
    virtual QVariantHash filtrableStrategy() const;
    virtual MUFormHeader&setFiltrableStrategy(const QVariant&value);

    //!
    //! \brief filterStyle
    //! \return
    //!
    virtual MUFormFilterStyle filterStyle() const;
    virtual MUFormHeader&setFilterStyle(const QVariant &value);

    //!
    //! \brief toVar
    //! \return
    //!
    virtual QVariant toVar()const;;

    //!
    //! \brief toHash
    //! \return
    //!
    QVariantHash toHash()const;;

    //!
    //! \brief toMap
    //! \return
    //!
    virtual QVariantMap toMap()const;;

private:
    QVariantHash v;
};
