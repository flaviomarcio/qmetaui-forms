#include "./mu_form_crud.h"

#define dPvt()\
auto&p = *reinterpret_cast<MUFormCrudItemPvt*>(this->p)

class MUFormCrudItemPvt{
public:
    MUFormCrudItem*parent=nullptr;
    MUFormLinkItemBase item;
    explicit MUFormCrudItemPvt(MUFormCrudItem*parent): item(parent)
    {
        this->parent=parent;
    }

    virtual ~MUFormCrudItemPvt()
    {
    }
};


MUFormCrudItem::MUFormCrudItem(QObject *parent):QStm::Object(parent)
{
    this->p=new MUFormCrudItemPvt(this);
}

MUFormCrudItem::~MUFormCrudItem()
{
    dPvt();
    delete&p;
}

const MUFormLinkItemBase &MUFormCrudItem::item() const
{
    dPvt();
    return p.item;
}

MUFormCrudItem &MUFormCrudItem::setItem(const MUFormLinkItemBase &newItem)
{
    dPvt();
    p.item = newItem;
    return*this;
}

MUFormCrud::MUFormCrud(QObject *parent):MUFormLinkCollectionBase(parent)
{
}
