#pragma once

#include <QMetaUi/Core>
#include "./mu_form_global.h"
#include "./mu_form_types.h"

//!
//! \brief The MUFormItems class
//!
class Q_QMETAUI_FORM_EXPORT MUFormItems:public QStm::Object{
    Q_OBJECT
public:
    //!
    //! \brief MUFormItems
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormItems(QObject*parent=nullptr):QStm::Object(parent)
    {
    }

    //!
    //! \brief clear
    //! \return
    //!
    virtual MUFormItems&clear()
    {
        this->___objectList.clear();
        return*this;
    }

    //!
    //! \brief fromList
    //! \param v
    //! \return
    //!
    virtual MUFormItems&fromList(const QVariant&v)
    {
        this->___objectList=v.toList();
        return*this;
    }

    //!
    //! \brief toVar
    //! \return
    //!
    virtual QVariant toVar()const
    {
        return this->___objectList;
    };

    //!
    //! \brief list
    //! \return
    //!
    virtual QVariantList&list()
    {
        return this->___objectList;
    }

private:
    QVariantList ___objectList;
};
