#pragma once

#include "./mu_form_items.h"
#include "./mu_form_headers.h"
#include "./mu_form_filters.h"
#include "./mu_form_links.h"
#include "./mu_form_types.h"
#include "./mu_form_headers.h"
#include "./mu_form_crud.h"
//#include "./mu_form_crud.h"

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

    /**
     * @brief name
     * @return
     */
    virtual QString id()const;
    virtual MUFormControls&id(const QVariant &v);

    /**
     * @brief type
     * @return
     */
    virtual QVariant type() const;
    virtual MUFormControls&type(const QVariant &v);
    virtual MUFormControls&setType(const QVariant &v);


    /**
     * @brief layout
     * @return
     */
    virtual QVariant layout() const;
    virtual MUFormControls&layout(const QVariant &v);
    virtual MUFormControls&setLayout(const QVariant &v);

    /**
     * @brief sort
     * @return
     */
    virtual QVariantHash sort() const;
    virtual MUFormControls&sort(const QVariant &v);
    virtual MUFormControls&setSort(const QVariant &v);

    /**
     * @brief text
     * @return
     */
    virtual QString text()const;
    virtual MUFormControls&text(const QVariant &v);

    /**
     * @brief settings
     * @param setting
     * @return
     */
    virtual MUFormControls&settings(const QVariant&setting);

    /**
     * @brief outPutStyle
     * @return
     */
    virtual MUFormOutPutStyle &outPutStyle() const;

    /**
     * @brief outPutStyle
     * @param value
     * @return
     */
    virtual MUFormControls &outPutStyle(const MUFormOutPutStyle &value);

    /**
     * @brief setOutPutStyle
     * @param value
     * @return
     */
    virtual MUFormControls &setOutPutStyle(const MUFormOutPutStyle &value);

    /**
     * @brief headers
     * @return
     */
    virtual MUFormHeaders<MUFormControls>&headers();

    /**
     * @brief filters
     * @return
     */
    virtual MUFormFilters<MUFormControls>&filters();

    /**
     * @brief links
     * @return
     */
    virtual MUFormLinks<MUFormControls>&links();

    /**
     * @brief crud
     * @return
     */
    virtual MUFormCrud<MUFormControls>&crud();

    /**
     * @brief items
     * @return
     */
    virtual MUFormItems<MUFormControls> &items();
    virtual MUFormControls &items(const QVariant&v);
    virtual MUFormControls &items(const ResultValue&lr);

    /**
     * @brief setValue
     * @param v
     * @return
     */
    virtual MUFormControls &setValue(const QVariant&v);
    virtual MUFormControls &setValue(const ResultValue&lr);

    /**
     * @brief clear
     * @return
     */
    virtual MUFormControls&clear();

    /**
     * @brief toOutput
     * @return
     */
    virtual ResultValue&o();
    virtual ResultValue&toOutput();

private:
    void*p=nullptr;
};
