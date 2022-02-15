#pragma once

#include "./mu_form_filter.h"
#include "./mu_form_object_model.h"

//!
//! \brief The MUFormFilters class
//!
class Q_QMETAUI_FORM_EXPORT MUFormFilters:public MUFormObjectModel{
    Q_OBJECT
public:

    //!
    //! \brief MUFormFilters
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormFilters(QObject*parent=nullptr);
    ~MUFormFilters();

    //!
    //! \brief objectMetaObject
    //! \return
    //!
    virtual const QMetaObject &objectMetaObject() const;

    //!
    //! \brief toVar
    //! \return
    //!
    virtual QVariant toVar()const;

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
    virtual void clear();

private:
    void*p=nullptr;
};
