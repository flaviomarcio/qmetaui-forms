#pragma once

#include "./mu_form_filter.h"

//!
//! \brief The MUFormFilters class
//!
class Q_QMETAUI_FORM_EXPORT MUFormFilters:public QStm::Object{
    Q_OBJECT
public:

    //!
    //! \brief MUFormFilters
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormFilters(QObject*parent=nullptr);

    //!
    //! \brief toVar
    //! \return
    //!
    virtual QVariant toVar()const;;

    //!
    //! \brief value
    //! \param v
    //! \return
    //!
    virtual MUFormFilter&value(const QString&v);
    virtual MUFormFilter&setValue(const QVariantHash&v);

    //!
    //! \brief clear
    //! \return
    //!
    virtual MUFormFilters&clear();

    //!
    //! \brief list
    //! \return
    //!
    virtual QList<MUFormFilter*>&list();

private:
    QList<MUFormFilter*> ___objectList;
};
