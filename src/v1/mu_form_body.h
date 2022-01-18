#pragma once

#include "./mu_form_controls.h"
#include "./mu_form_macro.h"

//!
//! \brief The MUFormBody class
//!
class MUFormBody : public QStm::Object
{
    Q_OBJECT
public:

    QMETAUI_FORM_DECLARE_TYPE(dftReportForm)
    QMETAUI_FORM_DECLARE_LAYOUT(dflVerticalControls)

    //!
    //! \brief MUFormBody
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormBody(QObject *parent = nullptr);

    //!
    //! \brief MUFormBody
    //! \param rows
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormBody(const ResultValue&rows, QObject *parent = nullptr);

    //!
    //! \brief ~MUFormBody
    //!
    ~MUFormBody();

    //!
    //! \brief id
    //! \return
    //!
    virtual QString id() const;

    //!
    //! \brief id
    //! \param v
    //! \return
    //!
    virtual MUFormBody&id(const QVariant &v);

    //!
    //! \brief setId
    //! \param v
    //! \return
    //!
    virtual MUFormBody&setId(const QVariant &v);

    //!
    //! \brief type
    //! \return
    //!
    virtual QVariant type() const;

    //!
    //! \brief type
    //! \param v
    //! \return
    //!
    virtual MUFormBody&type(const QVariant &v);

    //!
    //! \brief setType
    //! \param v
    //! \return
    //!
    virtual MUFormBody&setType(const QVariant &v);

    //!
    //! \brief layout
    //! \return
    //!
    virtual QVariant layout() const;

    //!
    //! \brief layout
    //! \param v
    //! \return
    //!
    virtual MUFormBody&layout(const QVariant &v);

    //!
    //! \brief setLayout
    //! \param v
    //! \return
    //!
    virtual MUFormBody&setLayout(const QVariant &v);

    //!
    //! \brief text
    //! \return
    //!
    virtual QString text() const;

    //!
    //! \brief text
    //! \param v
    //! \return
    //!
    virtual MUFormBody&text(const QVariant &v);

    //!
    //! \brief setText
    //! \param v
    //! \return
    //!
    virtual MUFormBody&setText(const QVariant &v);

    //!
    //! \brief sort
    //! \return
    //!
    virtual QVariantHash sort() const;

    //!
    //! \brief sort
    //! \param v
    //! \return
    //!
    virtual MUFormBody&sort(const QVariant &v);

    //!
    //! \brief setSort
    //! \param v
    //! \return
    //!
    virtual MUFormBody&setSort(const QVariant &v);

    //!
    //! \brief settings
    //! \param setting
    //! \return
    //!
    virtual MUFormBody&settings(const QVariant&setting);

    //!
    //! \brief controls
    //! \return
    //!
    virtual MUFormControls&controls();

    //!
    //! \brief headers
    //! \return
    //!
    virtual MUFormHeaders<MUFormControls>&headers();

    //!
    //! \brief filters
    //! \return
    //!
    virtual MUFormFilters<MUFormControls>&filters();

    //!
    //! \brief links
    //! \return
    //!
    virtual MUFormLinks<MUFormControls>&links();

    //!
    //! \brief items
    //! \return
    //!
    virtual MUFormItems<MUFormControls> &items();

    //!
    //! \brief items
    //! \param v
    //! \return
    //!
    virtual MUFormControls &items(const QVariant&v);

    //!
    //! \brief items
    //! \param lr
    //! \return
    //!
    virtual MUFormControls &items(const ResultValue&lr);

    //!
    //! \brief resultInfo
    //! \return
    //!
    virtual QStm::ResultInfo &resultInfo();

    //!
    //! \brief resultInfo
    //! \param v
    //! \return
    //!
    virtual MUFormControls &resultInfo(const QVariant&v);

    //!
    //! \brief setResultInfo
    //! \param resultInfo
    //! \return
    //!
    virtual MUFormControls &setResultInfo(const QStm::ResultInfo&resultInfo);

    //!
    //! \brief setValue
    //! \param v
    //! \return
    //!
    virtual MUFormBody &setValue(const QVariant&v);

    //!
    //! \brief setValue
    //! \param lr
    //! \return
    //!
    virtual MUFormBody &setValue(const ResultValue&lr);

    //!
    //! \brief clear
    //! \return
    //!
    virtual MUFormBody&clear();

    //!
    //! \brief o
    //! \return
    //!
    virtual ResultValue&o();

    //!
    //! \brief toOutput
    //! \return
    //!
    virtual ResultValue&toOutput();

    //!
    //! \brief initDescriptors
    //! \param object
    //! \return
    //!
    virtual MUFormBody&initDescriptors(QObject *object);

private:
    void*p=nullptr;
};
