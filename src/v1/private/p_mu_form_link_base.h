#pragma once
#include <QMetaUi/Core>
#include "../mu_form_global.h"
#include "../mu_form_types.h"

//!
//! \brief The MUFormLinkItemBase class
//!
class MUFormLinkItemBase : public QStm::Object{
    Q_OBJECT
public:
    Q_PROPERTY(QVariantHash header READ header WRITE setHeader NOTIFY headerChanged)
    Q_PROPERTY(QVariant method READ method WRITE setMethod NOTIFY methodChanged)
    Q_PROPERTY(QVariant ref READ ref WRITE setRef NOTIFY refChanged)
    Q_PROPERTY(QVariant hRef READ hRef WRITE setHRef NOTIFY hRefChanged)
    Q_PROPERTY(QVariant parameters READ parameters WRITE setParameters NOTIFY parametersChanged)

    //!
    //! \brief MUFormLinkItemBase
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormLinkItemBase(QObject*parent=nullptr);

    ~MUFormLinkItemBase();

    //!
    //! \brief operator =
    //! \param v
    //! \return
    //!
    MUFormLinkItemBase&operator=(const MUFormLinkItemBase&v);

    //!
    //! \brief uuid
    //! \return
    //!
    QUuid&uuid() const;

    //!
    //! \brief isMethodGet
    //! \return
    //!
    bool isMethodGet() const;

    //!
    //! \brief isMethodPost
    //! \return
    //!
    bool isMethodPost() const;

    //!
    //! \brief isMethodPut
    //! \return
    //!
    bool isMethodPut() const;

    //!
    //! \brief isMethodDelete
    //! \return
    //!
    bool isMethodDelete() const;

    //!
    //! \brief header
    //! \return
    //!
    QVariantHash&header() const;

    //!
    //! \brief setHeader
    //! \param value
    //! \return
    //!
    MUFormLinkItemBase&setHeader(const QVariant&value);

    //!
    //! \brief method
    //! \return
    //!
    QVariant&method() const;

    //!
    //! \brief setMethod
    //! \param value
    //! \return
    //!
    MUFormLinkItemBase&setMethod(const QVariant&value);

    //!
    //! \brief ref
    //! \return
    //!
    //!
    QVariant&ref() const;

    //!
    //! \brief setRef
    //! \param value
    //! \return
    //!
    MUFormLinkItemBase&setRef(const QVariant&value);

    //!
    //! \brief hRef
    //! \return
    //!
    QVariant&hRef() const;

    //!
    //! \brief setHRef
    //! \param value
    //! \return
    //!
    MUFormLinkItemBase&setHRef(const QVariant&value);

    //!
    //! \brief parameters
    //! \return
    //!
    QVariant&parameters() const;

    //!
    //! \brief setParameters
    //! \param value
    //! \return
    //!
    MUFormLinkItemBase&setParameters(const QVariant&value);

    //!
    //! \brief toVariant
    //! \return
    //!
    QVariant toVariant() const;

private:
    void*p=nullptr;
signals:
    void headerChanged();
    void methodChanged();
    void refChanged();
    void hRefChanged();
    void parametersChanged();
};

class MUFormLinkCollectionBase:public QStm::Object
{
    Q_OBJECT
public:

    explicit MUFormLinkCollectionBase(QObject*parent=nullptr);

    ~MUFormLinkCollectionBase();

    QVariant toVar() const;

    QObject&ref(MUFormLinkItemBase*link=nullptr);

    MUFormLinkItemBase*find(const QVariant&ref);

    MUFormLinkCollectionBase&clear();

    QHash<QString, MUFormLinkItemBase *> &list()const;
private:
    void*p=nullptr;

};
