#pragma once

#include "./mu_form_global.h"
#include "../../../qmetaui/src/v1/cpp/mu_request.h"
#include <QAbstractItemModel>

//!
//! \brief The MUFormRequestModel class
//!
class Q_MU_EXPORT MUFormRequestModel : public MURequest
{
    Q_OBJECT
public:
    Q_PROPERTY(QAbstractItemModel*headers READ headers WRITE setHeaders NOTIFY headersChanged)
    Q_PROPERTY(QAbstractItemModel*filters READ filters WRITE setFilters NOTIFY filtersChanged)
    Q_PROPERTY(QAbstractItemModel*items READ items WRITE setItems NOTIFY itemsChanged)
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(bool isEmpty READ isEmpty NOTIFY isEmptyChanged)

    //!
    //! \brief MUFormRequestModel
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormRequestModel(QObject *parent = nullptr);
    ~MUFormRequestModel();

    //!
    //! \brief count
    //! \return
    //!
    Q_INVOKABLE virtual int count();

    //!
    //! \brief isEmpty
    //! \return
    //!
    Q_INVOKABLE virtual bool isEmpty();

    //!
    //! \brief clear
    //!
    Q_INVOKABLE virtual void clear();

    //!
    //! \brief headers
    //! \return
    //!
    QAbstractItemModel *headers();
    void setHeaders(QAbstractItemModel*headers);

    //!
    //! \brief filters
    //! \return
    //!
    QAbstractItemModel *filters();
    void setFilters(QAbstractItemModel*filters);

    //!
    //! \brief model
    //! \return
    //!
    QAbstractItemModel *items();
    void setItems(QAbstractItemModel*items);

signals:
    //!
    //! \brief headersChanged
    //!
    void headersChanged();

    //!
    //! \brief filtersChanged
    //!
    void filtersChanged();

    //!
    //! \brief itemsChanged
    //!
    void itemsChanged();

    //!
    //! \brief countChanged
    //!
    void countChanged();

    //!
    //! \brief isEmptyChanged
    //!
    void isEmptyChanged();
private:
    void*p=nullptr;
};
