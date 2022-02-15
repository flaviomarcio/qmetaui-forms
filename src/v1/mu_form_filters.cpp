#include "mu_form_filters.h"

#define dPvt()\
auto&p = *reinterpret_cast<MUFormFiltersPvt*>(this->p)

class MUFormFiltersPvt{
public:
    MUFormFilters*parent=nullptr;
    QList<MUFormFilter*> ___objectList;
    explicit MUFormFiltersPvt(MUFormFilters*parent)
    {
        this->parent=parent;
    }

    virtual ~MUFormFiltersPvt()
    {
    }

    void clear()
    {
        qDeleteAll(this->___objectList);
        this->___objectList.clear();
    }
};

MUFormFilters::MUFormFilters(QObject *parent):MUFormObjectModel(parent)
{
    this->p=new MUFormFiltersPvt(this);
}

MUFormFilters::~MUFormFilters()
{
    dPvt();
    delete&p;
}

const QMetaObject &MUFormFilters::objectMetaObject() const
{
    return MUFormFilter::staticMetaObject;
}

QVariant MUFormFilters::toVar() const
{
    dPvt();
    QVariantList vList;
    for(auto&v:p.___objectList)
        vList<<v->toVar();
    return vList;
}

MUFormFilter &MUFormFilters::value(const QString &v)
{
    return this->setValue(QVariantHash{{vpType,v}});
}

MUFormFilter &MUFormFilters::setValue(const QVariantHash &v)
{
    dPvt();
    auto object=new MUFormFilter(this);
    object->setType(v.value(vpType));
    object->setValue(v.value(vpValue));
    object->setDefaultValue(v.value(vpDefaultValue));
    object->setText(v.value(vpText));
    object->setAlign(v.value(vpAlign));
    object->setWidth(v.value(vpWidth));
    object->setSortable(v.value(vpSortable));
    object->setFiltrable(v.value(vpFiltrable));
    object->setFilterStyle(v.value(vpFilterStyle));
    p.___objectList<<object;
    return*object;
}

void MUFormFilters::clear()
{
    dPvt();
    p.clear();
    MUFormObjectModel::clear();
}
