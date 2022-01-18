#pragma once

#include "./mu_form_link.h"

//!
//! \brief The MUFormLinks class
//!
class Q_QMETAUI_FORM_EXPORT MUFormLinks:public MUFormLinkCollectionBase{
    Q_OBJECT
public:
    explicit MUFormLinks(QObject*parent=nullptr):MUFormLinkCollectionBase(parent)
    {
    }

    virtual MUFormLinkItem&ref(const QVariant&ref)
    {

        auto object=MUFormLinkCollectionBase::find(ref);
        if(object==nullptr){
            object=new MUFormLinkItem(this);
            object->setRef(ref);
            MUFormLinkCollectionBase::ref(object);
        }
        return*dynamic_cast<MUFormLinkItem*>(object) ;
    }
};
