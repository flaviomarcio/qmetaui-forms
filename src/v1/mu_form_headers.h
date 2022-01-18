#pragma once

#include "./mu_form_header.h"

//!
//! \brief The MUFormHeaders class
//!
class Q_QMETAUI_FORM_EXPORT MUFormHeaders:public QStm::Object{
    Q_OBJECT
public:

    enum FilterStyle{
        dsAutoDectect=MUFormFilterStyle::fsAutoDectect
    };

    Q_ENUM(FilterStyle)


    explicit MUFormHeaders(QObject*parent=nullptr):QStm::Object(parent)
    {
    }

    virtual MUFormHeaders&clear()
    {
        this->___objectMap.clear();
        this->___objectList.clear();
        return*this;
    }

    virtual QVariant toVar()const
    {
        QVariantList vList;
        for(const auto&v:this->___objectList)
            vList<<v->toVar();
        return vList;
    };

    virtual QVariant toList()const
    {
        QVariantList vList;
        for(const auto&v:this->___objectList)
            vList<<v->toVar();
        return vList;
    };

    virtual MUFormHeader* get(const QString&v)
    {
        return this->___objectMap.value(v);
    }

    virtual MUFormHeaders&remove(const QString&v)
    {
        if(this->___objectMap.contains(v)){
            auto object=this->___objectMap.take(v);
            this->___objectList.removeOne(object);
            delete object;
        }
        return*this;
    }

    virtual MUFormHeader&value(const QString&v)
    {
        return this->value(QVariantHash{{vpValue,v}});
    }

    virtual MUFormHeader&value(const QVariantHash&v)
    {
        auto value=v.value(vpValue).toString();
        auto object=this->___objectMap.value(value);
        if(object==nullptr){
            object=new MUFormHeader(this);
            object->order(this->___objectMap.count());
            this->___objectList<<object;
            this->___objectMap.insert(value, object);
        }
        object->type(v.value(vpType));
        object->value(v.value(vpValue));
        object->defaultValue(v.value(vpDefaultValue));
        object->defaultSelect(v.value(vpDefaultSelect));
        object->text(v.value(vpText));
        object->align(v.value(vpAlign));
        object->width(v.value(vpWidth));
        object->visible(v.value(vpVisible));
        object->readOnly(v.value(vpReadOnly));
        object->editable(v.value(vpEditable));
        object->sortable(v.value(vpSortable));
        object->length(v.value(vpLength));
        object->filtrable(v.value(vpFiltrable));
        object->filtrableStrategy(v.value(vpFiltrableStrategy));
        object->filterStyle(v.value(vpFilterStyle));
        object->inputType(v.value(vpInputType));
        object->inputMask(v.value(vpInputMask));
        object->inputLinks(v.value(vtInputLinks));
        return*object;
    }

    virtual MUFormHeader&makeDefault()
    {
        static auto vAction=QVariantHash( { { vpValue, vpActions}, { vpText, qsl_null}, { vpSortable, false }, { vpVisible, true }, { vpWidth, qsl("0%") }});
        return this->value(vAction);
    }

    virtual MUFormHeaders&unMakeDefault()
    {
        return this->remove(vpActions);
    }

    virtual QList<MUFormHeader*>&list()
    {
        this->reOrder();
        return this->___objectList;
    }

    virtual void reOrder()
    {
        auto i=0;
        for(auto&v:this->___objectList)
            v->setOrder(i++);
    }

protected:
    QMap<QString, MUFormHeader*> ___objectMap;
    QList<MUFormHeader*> ___objectList;
};
