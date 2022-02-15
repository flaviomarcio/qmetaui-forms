#pragma once

#include "./mu_form_header.h"
#include "./mu_form_object_model.h"

//!
//! \brief The MUFormHeaders class
//!
class Q_QMETAUI_FORM_EXPORT MUFormHeaders:public MUFormObjectModel{
    Q_OBJECT
public:

    enum FilterStyle{
        dsAutoDectect=MUFormFilterStyle::fsAutoDectect
    };

    Q_ENUM(FilterStyle)

    //!
    //! \brief MUFormHeaders
    //! \param parent
    //!
    explicit MUFormHeaders(QObject*parent=nullptr);
    ~MUFormHeaders();

    //!
    //! \brief objectMetaObject
    //! \return
    //!
    virtual const QMetaObject &objectMetaObject() const;

    //!
    //! \brief clear
    //! \return
    //!
    virtual void clear();

    //!
    //! \brief toVar
    //! \return
    //!
    virtual QVariant toVar()const;

    //!
    //! \brief toList
    //! \return
    //!
    virtual QVariant toList()const;

    //!
    //! \brief get
    //! \param v
    //! \return
    //!
    virtual MUFormHeader*get(const QString&v);

    //!
    //! \brief remove
    //! \param v
    //! \return
    //!
    virtual MUFormHeaders&remove(const QString&v);

    //!
    //! \brief value
    //! \param v
    //! \return
    //!
    virtual MUFormHeader&value(const QString&v);

    //!
    //! \brief value
    //! \param v
    //! \return
    //!
    virtual MUFormHeader&value(const QVariantHash&v);

    //!
    //! \brief makeDefault
    //! \return
    //!
    virtual MUFormHeader&makeDefault();

    //!
    //! \brief unMakeDefault
    //! \return
    //!
    virtual MUFormHeaders&unMakeDefault();

    //!
    //! \brief list
    //! \return
    //!
    virtual QList<MUFormHeader*>&list();

    //!
    //! \brief reOrder
    //!
    virtual void reOrder();
private:
    void*p=nullptr;
};
