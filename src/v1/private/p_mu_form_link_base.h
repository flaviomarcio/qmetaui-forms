#pragma once
#include <QMetaUi/Core>
#include "../mu_form_global.h"
#include "../mu_form_types.h"

class MUFormBody;

class MUFormLinkItemBase : public QStm::Object{
    Q_OBJECT
public:
    Q_PROPERTY(QVariantHash header READ header WRITE setHeader)
    Q_PROPERTY(QVariant method READ method WRITE setMethod)
    Q_PROPERTY(QVariant ref READ ref WRITE setRef)
    Q_PROPERTY(QVariant hRef READ hRef WRITE setHRef)
    Q_PROPERTY(QVariant parameters READ parameters WRITE setParameters)

    Q_INVOKABLE explicit MUFormLinkItemBase(QObject*parent=nullptr);

    ~MUFormLinkItemBase();

    QUuid&uuid() const;

    MUFormBody&d();

    bool isMethodGet() const;

    bool isMethodPost() const;

    bool isMethodPut() const;

    bool isMethodDelete() const;

    QVariantHash&header() const;

    MUFormLinkItemBase&setHeader(const QVariant&value);

    QVariant&method() const;

    MUFormLinkItemBase&setMethod(const QVariant&value);

    QVariant&ref() const;

    MUFormLinkItemBase&setRef(const QVariant&value);

    QVariant&hRef() const;

    MUFormLinkItemBase&setHRef(const QVariant&value);

    QVariant&parameters() const;

    MUFormLinkItemBase&setParameters(const QVariant&value);

    QVariant toVariant() const;

private:
    void*p=nullptr;
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
