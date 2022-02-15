#pragma once

#include "./mu_form_global.h"
#include <QAbstractItemModel>

//!
//! \brief The MUFormObjectModel class
//!
class Q_QMETAUI_FORM_EXPORT MUFormObjectModel : public QAbstractItemModel
{
    Q_OBJECT
    friend class MUFormObjectModelPvt;
public:
    //!
    //! \brief MUFormObjectModel
    //! \param parent
    //!
    explicit MUFormObjectModel(QObject *parent = nullptr);
    ~MUFormObjectModel();

    //!
    //! \brief index
    //! \param row
    //! \param column
    //! \param parent
    //! \return
    //!
    Q_INVOKABLE virtual QModelIndex index(int row, int column,
                                          const QModelIndex &parent = QModelIndex()) const override;

    //!
    //! \brief parent
    //! \param child
    //! \return
    //!
    Q_INVOKABLE virtual QModelIndex parent(const QModelIndex &child) const override;

    //!
    //! \brief data
    //! \param index
    //! \param role
    //! \return
    //!
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    //!
    //! \brief roleNames
    //! \return
    //!
    QHash<int,QByteArray> roleNames() const override;

    //!
    //! \brief rowCount
    //! \param parent
    //! \return
    //!
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    //!
    //! \brief columnCount
    //! \param parent
    //! \return
    //!
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    //!
    //! \brief objectMetaObject
    //! \return
    //!
    virtual const QMetaObject &objectMetaObject() const=0;

    //!
    //! \brief fromVar
    //! \param v
    //! \return
    //!
    virtual bool fromVar(const QVariant &v);

    //!
    //! \brief fromList
    //! \param list
    //! \return
    //!
    virtual bool fromList(const QVariantList &list);


    //!
    //! \brief clear
    //!
    virtual void clear();

    //!
    //! \brief objectList
    //! \return
    //!
    virtual QObjectList &objectList();
    virtual MUFormObjectModel&setObjectList(const QObjectList&objectList);


signals:
private:
    void*p=nullptr;
};
