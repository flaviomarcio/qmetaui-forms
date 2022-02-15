#include "./mu_form_items.h"

#include "../../../qstm/src/qstm_types.h"
#include "../../../qstm/src/qstm_object.h"
#include <QMetaProperty>
#include <QJsonDocument>
#include <QJsonArray>

#define dPvt()\
auto&p = *reinterpret_cast<MUFormItemsPvt*>(this->p)

class MUFormItemsPvt{
public:
    MUFormItems*parent=nullptr;
    QVariantList ___objectList;
    QHash<int,QByteArray> rolesNames;
    bool inited=false;
    explicit MUFormItemsPvt(MUFormItems*parent)
    {
        this->parent=parent;
    }

    virtual ~MUFormItemsPvt()
    {
    }

    void clear()
    {
        this->inited=false;
        this->rolesNames.clear();
    }
};

MUFormItems::MUFormItems(QObject *parent)
    : QAbstractItemModel{parent}
{
    this->p=new MUFormItemsPvt(this);
}

MUFormItems::~MUFormItems()
{
    dPvt();
    delete&p;
}

QModelIndex MUFormItems::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return this->createIndex(row, column, nullptr);
}

QModelIndex MUFormItems::parent(const QModelIndex &child) const
{
    Q_UNUSED(child)
    return {};
}

QVariant MUFormItems::data(const QModelIndex &index, int role) const
{
    dPvt();
    auto obj=static_cast<QObject*>(index.internalPointer());
    if(obj==nullptr)
        return {};

    auto vList=p.___objectList.value(index.row()).toList();

    if(vList.isEmpty())
        return {};

    if(role>=vList.count())
        return {};

    return vList.at(role);
}

QHash<int, QByteArray> MUFormItems::roleNames() const
{
    dPvt();
    return p.rolesNames;
}

int MUFormItems::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    dPvt();
    return p.___objectList.count();
}

int MUFormItems::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    dPvt();
    return p.rolesNames.count();
}

bool MUFormItems::isEmpty()
{
    dPvt();
    return p.___objectList.isEmpty();
}

bool MUFormItems::fromVar(const QVariant &v)
{
    switch (qTypeId(v)) {
    case QMetaType_QVariantList:
    case QMetaType_QStringList:
        return this->fromList(v.toList());
    default:
        return this->fromList(QJsonDocument::fromJson(v.toByteArray()).array().toVariantList());
    }
}

bool MUFormItems::fromList(const QVariantList &list)
{
    dPvt();
    p.clear();
    MUFormItems::setObjectList(list);
    return p.___objectList.isEmpty();
}

void MUFormItems::clear()
{
    dPvt();
    auto rowCount = this->rowCount({});

    if ( rowCount == 0 )
        return;

    beginRemoveRows( {} , 0, rowCount-1 );
    p.clear();
    endRemoveRows();
}

QVariantList &MUFormItems::objectList()
{
    dPvt();
    return p.___objectList;
}

MUFormItems &MUFormItems::setObjectList(const QVariantList &objectList)
{
    dPvt();
    p.___objectList=objectList;
    this->beginInsertRows( {} , 0, objectList.count() );
    this->endInsertRows();//finish insert
    return*this;
}


