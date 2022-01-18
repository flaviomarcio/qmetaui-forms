#include "./mu_form_link_base.h"

namespace PrivateQMetaUiForm {

#define dPvtI()\
auto&p = *reinterpret_cast<MUFormLinkItemPvt*>(this->p)\

class MUFormLinkItemPvt : public QObject{
public:
    QUuid uuid=QUuid::createUuid();
    QVariantHash header;
    QVariant method;
    QVariant ref;
    QVariant hRef;
    QVariant parameters;
    QObject*parent=nullptr;
    QObject*___d=nullptr;
    explicit MUFormLinkItemPvt(QObject*parent):QObject(parent)
    {
    }
    ~MUFormLinkItemPvt()
    {
    }
};

#define dPvtA()\
auto&p = *reinterpret_cast<MUFormLinkBaseCollectionPvt*>(this->p)\

class MUFormLinkBaseCollectionPvt : public QObject{
public:
    QObject*parent=nullptr;
    QObject*___d=nullptr;
    QHash<QString, MUFormLinkItem*> ___objectList;
    explicit MUFormLinkBaseCollectionPvt(QObject*parent):QObject(parent)
    {
    }
    ~MUFormLinkBaseCollectionPvt(){
    }
};

MUFormLinkItem::MUFormLinkItem(QObject *dtpParent, QObject *parent):QStm::Object(parent)
{
    this->p=new MUFormLinkItemPvt(this);
    dPvtI();
    p.___d=dtpParent;
}

MUFormLinkItem::~MUFormLinkItem()
{
}

QUuid &MUFormLinkItem::uuid() const
{
    dPvtI();
    return p.uuid;
}

QObject &MUFormLinkItem::d()
{
    dPvtI();
    return*p.___d;
}

bool MUFormLinkItem::isMethodGet() const
{
    dPvtI();
    return (p.method==qbl("get"));
}

bool MUFormLinkItem::isMethodPost() const
{
    dPvtI();
    return (p.method==qbl("post"));
}

bool MUFormLinkItem::isMethodPut() const
{
    dPvtI();
    return (p.method==qbl("put"));
}

bool MUFormLinkItem::isMethodDelete() const
{
    dPvtI();
    return (p.method==qbl("delete"));
}

QVariantHash &MUFormLinkItem::header() const
{
    dPvtI();
    return p.header;
}

MUFormLinkItem &MUFormLinkItem::setHeader(const QVariant &value)
{
    dPvtI();
    p.header=value.toHash();
    return*this;
}

QVariant &MUFormLinkItem::method() const
{
    dPvtI();
    return p.method;
}

MUFormLinkItem &MUFormLinkItem::setMethod(const QVariant &value)
{
    dPvtI();
    p.method=value.toString().trimmed();
    return*this;
}

QVariant &MUFormLinkItem::ref() const
{
    dPvtI();
    return p.ref;
}

MUFormLinkItem &MUFormLinkItem::setRef(const QVariant &value)
{
    dPvtI();
    p.ref=value;
    return*this;
}

QVariant &MUFormLinkItem::hRef() const
{
    dPvtI();
    return p.hRef;
}

MUFormLinkItem &MUFormLinkItem::setHRef(const QVariant &value)
{
    dPvtI();
    p.hRef=value;
    return*this;
}

QVariant &MUFormLinkItem::parameters() const
{
    dPvtI();
    return p.parameters;
}

MUFormLinkItem &MUFormLinkItem::setParameters(const QVariant &value)
{
    dPvtI();
    auto typeId=qTypeId(value);
    if(QStmTypesListString.contains(typeId)){
        auto name=value.toString().trimmed();
        if(name.isEmpty())
            p.parameters=QVariantHash{{name, qsl("${%1}").arg(name)}};
    }
    p.parameters=value;
    return*this;
}

QVariant MUFormLinkItem::toVariant() const
{
    auto v=this->toHash();
    return v;
}

MUFormLinkCollection::MUFormLinkCollection(QObject *dtoParent, QObject *parent):QStm::Object(parent)
{
    this->p = new MUFormLinkBaseCollectionPvt(this);
    dPvtA();
    p.___d=dtoParent;
}

MUFormLinkCollection::~MUFormLinkCollection(){
}

QVariant MUFormLinkCollection::toVar() const
{
    dPvtA();
    QVariantList vList;
    for(auto&v:p.___objectList)
        vList<<v->toVariant();
    return vList;
}

QObject &MUFormLinkCollection::d()
{
    dPvtA();
    return*p.___d;
}

QObject &MUFormLinkCollection::ref(MUFormLinkItem *link)
{
    dPvtA();
    if(link==nullptr)
        link=new MUFormLinkItem(p.___d, this);
    else
        link->setParent(this);
    p.___objectList.insert(link->uuid().toString(), link);
    return*link;
}

MUFormLinkItem *MUFormLinkCollection::find(const QVariant &ref)
{
    dPvtA();
    auto _ref=ref.toString().toUtf8().toLower().trimmed();
    QHashIterator<QString, MUFormLinkItem*> i(p.___objectList);
    while (i.hasNext()) {
        i.next();
        auto iRef=i.value();
        if(iRef->ref().toString().toLower().trimmed()!=_ref)
            continue;
        return iRef;
    }
    return nullptr;
}

MUFormLinkCollection &MUFormLinkCollection::clear(){
    dPvtA();
    p.___objectList.clear();
    return*this;
}

QHash<QString, MUFormLinkItem *> &MUFormLinkCollection::list() const
{
    dPvtA();
    return p.___objectList;
}

}
