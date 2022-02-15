#include "./mu_form_object_model.h"
#include "../../../qstm/src/qstm_types.h"
#include "../../../qstm/src/qstm_object.h"
#include <QMetaProperty>
#include <QJsonDocument>
#include <QJsonArray>

#define dPvt()\
auto&p = *reinterpret_cast<MUFormObjectModelPvt*>(this->p)

class MUFormObjectModelPvt{
public:
    MUFormObjectModel*parent=nullptr;
    QObjectList ___objectList;
    QHash<int, QMetaProperty> propertys;
    QHash<int,QByteArray> rolesNames;
    bool inited=false;
    explicit MUFormObjectModelPvt(MUFormObjectModel*parent)
    {
        this->parent=parent;
    }

    virtual ~MUFormObjectModelPvt()
    {
    }

    void init()
    {
        if(inited)
            return;
        inited=true;
        const auto&metaObject=this->parent->objectMetaObject();
        for (int p = 0; p < metaObject.propertyCount(); ++p) {
            int role=Qt::UserRole+(p+1);
            auto property=metaObject.property(role);
            this->propertys[role]=property;
            this->rolesNames[role]=property.name();
        }
    }

    void clear()
    {
        this->inited=false;
        this->propertys.clear();
        this->rolesNames.clear();
    }
};

MUFormObjectModel::MUFormObjectModel(QObject *parent)
    : QAbstractItemModel{parent}
{
    this->p=new MUFormObjectModelPvt(this);
}

MUFormObjectModel::~MUFormObjectModel()
{
    dPvt();
    delete&p;
}

QModelIndex MUFormObjectModel::index(int row, int column, const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    dPvt();
    return this->createIndex(row, column, p.___objectList.at(row));
}

QModelIndex MUFormObjectModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child)
    return {};
}

QVariant MUFormObjectModel::data(const QModelIndex &index, int role) const
{
    dPvt();
    auto property = p.propertys.value(role);
    if(!property.isValid())
        return {};

    auto obj=static_cast<QObject*>(index.internalPointer());
    if(obj==nullptr)
        return {};

    return property.read(obj);
}

QHash<int, QByteArray> MUFormObjectModel::roleNames() const
{
    dPvt();
    return p.rolesNames;
}

int MUFormObjectModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    dPvt();
    return p.___objectList.count();
}

int MUFormObjectModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    dPvt();
    return p.rolesNames.count();
}

bool MUFormObjectModel::fromVar(const QVariant &v)
{
    switch (qTypeId(v)) {
    case QMetaType_QVariantList:
    case QMetaType_QStringList:
        return this->fromList(v.toList());
    default:
        return this->fromList(QJsonDocument::fromJson(v.toByteArray()).array().toVariantList());
    }
}

bool MUFormObjectModel::fromList(const QVariantList &list)
{
    dPvt();
    p.clear();
    QObjectList oList;
    const auto&metaObject=this->objectMetaObject();
    for(auto&v:list){
        auto obj=metaObject.newInstance(Q_ARG(QObject*, this));
        if(obj==nullptr)
            continue;
        auto item=dynamic_cast<QStm::Object*>(obj);

        if(item==nullptr){
            delete obj;
            continue;
        }
        if(!item->fromVar(v)){
            delete item;
            continue;
        }
        oList<<obj;
        p.___objectList<<obj;
    }
    MUFormObjectModel::setObjectList(oList);
    return p.___objectList.isEmpty();
}

void MUFormObjectModel::clear()
{
    dPvt();
    auto rowCount = this->rowCount({});

    if ( rowCount == 0 )
        return;

    beginRemoveRows( {} , 0, rowCount-1 );
    p.clear();
    endRemoveRows();
}

QObjectList &MUFormObjectModel::objectList()
{
    dPvt();
    return p.___objectList;
}

MUFormObjectModel &MUFormObjectModel::setObjectList(const QObjectList &objectList)
{
    dPvt();
    p.___objectList=objectList;
    this->beginInsertRows( {} , 0, objectList.count() );
    this->endInsertRows();//finish insert
    return*this;
}


