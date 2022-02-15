#include "./mu_form_request_model.h"
#include "./mu_form_filters.h"
#include "./mu_form_headers.h"
#include "./mu_form_items.h"

#include "../../../qmetaui/src/v1/cpp/mu_model_table.h"

#define dPvt()\
auto&p = *reinterpret_cast<MUFormRequestModelPvt*>(this->p)

class MUFormRequestModelPvt:public QObject{
public:
    MUFormRequestModel*parent=nullptr;
    MUFormHeaders headers;
    MUFormFilters filters;
    MUFormItems items;
    explicit MUFormRequestModelPvt(MUFormRequestModel*parent):
        QObject(parent),
        headers(parent),
        filters(parent),
        items(parent)
    {
        this->parent=parent;
    }

    virtual ~MUFormRequestModelPvt()
    {
    }
};

MUFormRequestModel::MUFormRequestModel(QObject *parent) : MURequest(parent)
{
    this->p=new MUFormRequestModelPvt(this);
}

MUFormRequestModel::~MUFormRequestModel()
{
    dPvt();
    delete&p;
}

int MUFormRequestModel::count()
{
    dPvt();
    return p.items.rowCount();
}

bool MUFormRequestModel::isEmpty()
{
    dPvt();
    return p.items.isEmpty();
}

void MUFormRequestModel::clear()
{
    dPvt();
    p.items.clear();
    emit itemsChanged();
}

QAbstractItemModel *MUFormRequestModel::headers()
{
    dPvt();
    return&p.headers;
}

void MUFormRequestModel::setHeaders(QAbstractItemModel *headers)
{
    Q_UNUSED(headers)
}

QAbstractItemModel *MUFormRequestModel::filters()
{
    dPvt();
    return&p.filters;
}

void MUFormRequestModel::setFilters(QAbstractItemModel *filters)
{
    Q_UNUSED(filters)
}

QAbstractItemModel *MUFormRequestModel::items()
{
    dPvt();
    return&p.items;
}

void MUFormRequestModel::setItems(QAbstractItemModel *items)
{
    Q_UNUSED(items)
}

