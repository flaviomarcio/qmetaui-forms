#pragma once

#include "./mu_form_items.h"
#include "./mu_form_headers.h"
#include "./mu_form_filters.h"
#include "./mu_form_links.h"
#include "./mu_form_types.h"
#include "./mu_form_headers.h"
#include "./mu_form_crud.h"

//!
//! \brief The MUFormControls class
//!
class Q_QMETAUI_FORM_EXPORT MUFormControls : public QStm::Object
{
    Q_OBJECT
public:

    //!
    //! \brief MUFormControls
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormControls(QObject *parent = nullptr);

    ~MUFormControls();

    //!
    //! \brief resultInfo
    //! \return
    //!
    virtual QStm::ResultInfo&resultInfo();
    virtual MUFormControls&setResultInfo(const QStm::ResultInfo&resultInfo);

    //!
    //! \brief id
    //! \return
    //!
    virtual QString id()const;
    virtual MUFormControls&id(const QVariant &v);

    //!
    //! \brief type
    //! \return
    //!
    virtual QVariant type() const;
    virtual MUFormControls&setType(const QVariant &v);

    //!
    //! \brief layout
    //! \return
    //!
    virtual QVariant layout() const;
    virtual MUFormControls&setLayout(const QVariant &v);

    //!
    //! \brief sort
    //! \return
    //!
    virtual QVariantHash sort() const;
    virtual MUFormControls&setSort(const QVariant &v);

    //!
    //! \brief text
    //! \return
    //!
    virtual QString text()const;
    virtual MUFormControls&setText(const QVariant &v);

    //!
    //! \brief outPutStyle
    //! \return
    //!
    virtual MUFormOutPutStyle &outPutStyle() const;
    virtual MUFormControls &setOutPutStyle(const MUFormOutPutStyle &value);

    //!
    //! \brief headers
    //! \return
    //!
    virtual MUFormHeaders&headers();

    //!
    //! \brief filters
    //! \return
    //!
    virtual MUFormFilters&filters();

    //!
    //! \brief links
    //! \return
    //!
    virtual MUFormLinks&links();

    //!
    //! \brief crud
    //! \return
    //!
    virtual MUFormCrud&crud();

    //!
    //! \brief items
    //! \return
    //!
    virtual MUFormItems &items();
    virtual MUFormControls &setItems(const QVariant&v);
    virtual MUFormControls &setItems(const ResultValue&lr);

    //!
    //! \brief setValue
    //! \param v
    //! \return
    //!
    virtual MUFormControls &setValue(const QVariant&v);
    virtual MUFormControls &setValue(const ResultValue&lr);

    //!
    //! \brief setSettings
    //! \param setting
    //! \return
    //!
    virtual MUFormControls&setSettings(const QVariant&setting);


    //!
    //! \brief clear
    //! \return
    //!
    virtual MUFormControls&clear();

private:
    void*p=nullptr;
};
