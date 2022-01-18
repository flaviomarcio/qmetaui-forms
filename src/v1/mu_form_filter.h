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

    //!
    //! \brief MUFormFilter
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormFilter(QObject*parent=nullptr);

    //!
    //! \brief type
    //! \return
    //!
    virtual QVariant type() const;
    virtual MUFormFilter&setType(const QVariant &type);

    //!
    //! \brief value
    //! \return
    //!
    virtual QByteArray value() const;
    virtual MUFormFilter&setValue(const QVariant &value);

    //!
    //! \brief defaultValue
    //! \return
    //!
    virtual QString defaultValue() const;
    virtual MUFormFilter&setDefaultValue(const QVariant &value);

    //!
    //! \brief comboValue
    //! \return
    //!
    virtual QString comboValue() const;
    virtual MUFormFilter&setComboValue(const QVariant &value);

    //!
    //! \brief text
    //! \return
    //!
    virtual QString text() const;
    virtual MUFormFilter&setText(const QVariant &value);

    //!
    //! \brief align
    //! \return
    //!
    virtual QVariant align() const;
    virtual MUFormFilter&setAlign(const QVariant& value);

    //!
    //! \brief width
    //! \return
    //!
    virtual QVariant width() const;
    virtual MUFormFilter&setWidth(const QVariant& value);

    //!
    //! \brief sortable
    //! \return
    //!
    virtual bool sortable() const;
    virtual MUFormFilter&setSortable(const QVariant &value);

    //!
    //! \brief filtrable
    //! \return
    //!
    virtual bool filtrable() const;
    virtual MUFormFilter&setFiltrable(const QVariant &value);

    //!
    //! \brief filterStyle
    //! \return
    //!
    virtual MUFormFilterStyle filterStyle() const;
    virtual MUFormFilter&setFilterStyle(const QVariant &value);

    //!
    //! \brief toVariant
    //! \return
    //!
    virtual QVariant toVariant()const;;

private:
    QVariantHash v;
};
