#pragma once
#include <QMetaUi/Core>
#include "../mu_form_global.h"
#include "../mu_form_types.h"

namespace PrivateQMetaUiForm {

class MUFormLinkItem : public QStm::Object{
    Q_OBJECT
public:
    Q_PROPERTY(QVariantHash header READ header WRITE setHeader)
    Q_PROPERTY(QVariant method READ method WRITE setMethod)
    Q_PROPERTY(QVariant ref READ ref WRITE setRef)
    Q_PROPERTY(QVariant hRef READ hRef WRITE setHRef)
    Q_PROPERTY(QVariant parameters READ parameters WRITE setParameters)

    Q_INVOKABLE explicit MUFormLinkItem(QObject*dtpParent, QObject*parent=nullptr);

    ~MUFormLinkItem();

    QUuid&uuid() const;

    QObject&d();

    bool isMethodGet() const;

    bool isMethodPost() const;

    bool isMethodPut() const;

    bool isMethodDelete() const;

    QVariantHash&header() const;

    MUFormLinkItem&setHeader(const QVariant&value);

    QVariant&method() const;

    MUFormLinkItem&setMethod(const QVariant&value);

    QVariant&ref() const;

    MUFormLinkItem&setRef(const QVariant&value);

    QVariant&hRef() const;

    MUFormLinkItem&setHRef(const QVariant&value);

    QVariant&parameters() const;

    MUFormLinkItem&setParameters(const QVariant&value);

    QVariant toVariant() const;

private:
    void*p=nullptr;
};

class MUFormLinkCollection:public QStm::Object
{
    Q_OBJECT
public:

    explicit MUFormLinkCollection(QObject*dtoParent, QObject*parent=nullptr);

    ~MUFormLinkCollection();

    QVariant toVar() const;

    QObject&d();

    QObject&ref(MUFormLinkItem*link=nullptr);

    MUFormLinkItem*find(const QVariant&ref);

    MUFormLinkCollection&clear();

    QHash<QString, MUFormLinkItem *> &list()const;
private:
    void*p=nullptr;
};

}
