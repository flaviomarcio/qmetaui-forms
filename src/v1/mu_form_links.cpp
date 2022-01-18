#include "mu_form_links.h"

MUFormLinks::MUFormLinks(QObject *parent):MUFormLinkCollectionBase(parent)
{
}

MUFormLinkItem &MUFormLinks::ref(const QVariant &ref)
{

    auto object=MUFormLinkCollectionBase::find(ref);
    if(object==nullptr){
        object=new MUFormLinkItem(this);
        object->setRef(ref);
        MUFormLinkCollectionBase::ref(object);
    }
    return*dynamic_cast<MUFormLinkItem*>(object) ;
}
