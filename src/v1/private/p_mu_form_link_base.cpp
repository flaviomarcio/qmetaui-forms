#include "./p_mu_form_link_base.h"
#include "../mu_form_body.h"

#define dPvtI()\
auto&p = *reinterpret_cast<MUFormLinkItemPvt*>(this->p)\

class Q_QMETAUI_FORM_EXPORT MUFormLinkItemPvt : public QObject{
public:
    QUuid uuid=QUuid::createUuid();
    QVariantHash header;
    QVariant method;
    QVariant ref;
    QVariant hRef;
    QVariant parameters;
    QObject*parent=nullptr;
    explicit MUFormLinkItemPvt(QObject*parent):QObject(parent)
    {
    }
    ~MUFormLinkItemPvt()
    {
    }
};

#define dPvtA()\
auto&p = *reinterpret_cast<MUFormLinkBaseCollectionPvt*>(this->p)\

class Q_QMETAUI_FORM_EXPORT MUFormLinkBaseCollectionPvt : public QObject{
public:
    QObject*parent=nullptr;
    QHash<QString, MUFormLinkItemBase*> ___objectList;
    explicit MUFormLinkBaseCollectionPvt(QObject*parent):QObject(parent)
    {
    }
};

MUFormLinkItemBase::MUFormLinkItemBase(QObject *parent):QStm::Object(parent)
{
    this->p=new MUFormLinkItemPvt(this);
}

MUFormLinkItemBase::~MUFormLinkItemBase()
{
}

QUuid &MUFormLinkItemBase::uuid() const
{
    dPvtI();
    return p.uuid;
}

bool MUFormLinkItemBase::isMethodGet() const
{
    dPvtI();
    return (p.method==qbl("get"));
}

bool MUFormLinkItemBase::isMethodPost() const
{
    dPvtI();
    return (p.method==qbl("post"));
}

bool MUFormLinkItemBase::isMethodPut() const
{
    dPvtI();
    return (p.method==qbl("put"));
}

bool MUFormLinkItemBase::isMethodDelete() const
{
    dPvtI();
    return (p.method==qbl("delete"));
}

QVariantHash &MUFormLinkItemBase::header() const
{
    dPvtI();
    return p.header;
}

MUFormLinkItemBase &MUFormLinkItemBase::setHeader(const QVariant &value)
{
    dPvtI();
    p.header=value.toHash();
    return*this;
}

QVariant &MUFormLinkItemBase::method() const
{
    dPvtI();
    return p.method;
}

MUFormLinkItemBase &MUFormLinkItemBase::setMethod(const QVariant &value)
{
    dPvtI();
    p.method=value.toString().trimmed();
    return*this;
}

QVariant &MUFormLinkItemBase::ref() const
{
    dPvtI();
    return p.ref;
}

MUFormLinkItemBase &MUFormLinkItemBase::setRef(const QVariant &value)
{
    dPvtI();
    p.ref=value;
    return*this;
}

QVariant &MUFormLinkItemBase::hRef() const
{
    dPvtI();
    return p.hRef;
}

MUFormLinkItemBase &MUFormLinkItemBase::setHRef(const QVariant &value)
{
    dPvtI();
    p.hRef=value;
    return*this;
}

QVariant &MUFormLinkItemBase::parameters() const
{
    dPvtI();
    return p.parameters;
}

MUFormLinkItemBase &MUFormLinkItemBase::setParameters(const QVariant &value)
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

QVariant MUFormLinkItemBase::toVariant() const
{
    auto v=this->toHash();
    return v;
}

MUFormLinkCollectionBase::MUFormLinkCollectionBase(QObject *parent):QStm::Object(parent)
{
    this->p = new MUFormLinkBaseCollectionPvt(this);
}

MUFormLinkCollectionBase::~MUFormLinkCollectionBase()
{
}

QVariant MUFormLinkCollectionBase::toVar() const
{
    dPvtA();
    QVariantList vList;
    for(auto&v:p.___objectList)
        vList<<v->toVariant();
    return vList;
}

QObject &MUFormLinkCollectionBase::ref(MUFormLinkItemBase *link)
{
    dPvtA();
    if(link==nullptr)
        link=new MUFormLinkItemBase(this);
    else
        link->setParent(this);
    p.___objectList.insert(link->uuid().toString(), link);
    return*link;
}

MUFormLinkItemBase *MUFormLinkCollectionBase::find(const QVariant &ref)
{
    dPvtA();
    auto _ref=ref.toString().toUtf8().toLower().trimmed();
    QHashIterator<QString, MUFormLinkItemBase*> i(p.___objectList);
    while (i.hasNext()) {
        i.next();
        auto iRef=i.value();
        if(iRef->ref().toString().toLower().trimmed()!=_ref)
            continue;
        return iRef;
    }
    return nullptr;
}

MUFormLinkCollectionBase &MUFormLinkCollectionBase::clear(){
    dPvtA();
    p.___objectList.clear();
    return*this;
}

QHash<QString, MUFormLinkItemBase *> &MUFormLinkCollectionBase::list() const
{
    dPvtA();
    return p.___objectList;
}
