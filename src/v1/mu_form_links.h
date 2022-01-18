#pragma once

#include "./mu_form_link.h"

template <class T>
//!
//! \brief The MUFormLinks class
//!
class MUFormLinks:public PrivateQMetaUiForm::MUFormLinkCollection
{
public:
    explicit MUFormLinks(QObject*dtoParent, QObject*parent=nullptr):PrivateQMetaUiForm::MUFormLinkCollection(dtoParent, parent)
    {
    }

    virtual T&d()
    {
        auto object=&PrivateQMetaUiForm::MUFormLinkCollection::d();
        return*dynamic_cast<T*>(object);
    }

    virtual MUFormLinkItem<T>&ref(const QVariant&ref)
    {

        auto object=PrivateQMetaUiForm::MUFormLinkCollection::find(ref);
        if(object==nullptr){
            object=new MUFormLinkItem<T>(&this->d(), this);
            object->setRef(ref);
            PrivateQMetaUiForm::MUFormLinkCollection::ref(object);
        }
        return*dynamic_cast<MUFormLinkItem<T>*>(object) ;
    }
};
