#pragma once

#include <QtQml>
#include <QMetaUi/Core>
#include "./mu_form_global.h"
#include "./mu_form_types.h"

//!
//! \brief The MUFormControlCache class
//!
class Q_QMETAUI_FORM_EXPORT MUFormControlCache : public QObject
{
    Q_OBJECT
public:

    Q_PROPERTY(QQuickItem *quickParent READ quickParent WRITE setQuickParent RESET resetQuickParent NOTIFY quickParentChanged)
    Q_PROPERTY(QQuickItem *quickItem READ quickItem WRITE setQuickItem RESET resetQuickItem NOTIFY quickItemChanged)

    //!
    //! \brief MUFormControlCache
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormControlCache(QObject *parent = nullptr);

    //!
    //! \brief start
    //! \return
    //!
    Q_INVOKABLE virtual bool start();

    //!
    //! \brief cancel
    //! \return
    //!
    Q_INVOKABLE virtual bool cancel();

    //!
    //! \brief quickParent
    //! \return
    //!
    QQuickItem *quickParent() const;
    void setQuickParent(QQuickItem *newQuickParent);
    void resetQuickParent();

    //!
    //! \brief quickItem
    //! \return
    //!
    QQuickItem *quickItem() const;
    void setQuickItem(QQuickItem *newQuickItem);
    void resetQuickItem();    

Q_SIGNALS:
    void loading();
    void loaded();
    void error(QString error, QString message);
    void finished();
    void quickItemChanged();
    void quickParentChanged();

private:
    void*p=nullptr;
};
