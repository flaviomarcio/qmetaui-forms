#pragma once

#include "./mu_form_controls.h"
#include "./mu_form_macro.h"

//!
//! \brief The MUFormBody class
//!
class Q_QMETAUI_FORM_EXPORT MUFormBody : public QStm::Object{
    Q_OBJECT
public:

    Q_PROPERTY(QString resource READ resource WRITE setResource NOTIFY resourceChanged)

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
    //! \brief operator =
    //! \param v
    //! \return
    //!
    MUFormBody&operator=(const MUFormBody&v);

    //!
    //! \brief id
    //! \return
    //!
    virtual QString resource() const;
    virtual MUFormBody&setResource(const QVariant &v);

    //!
    //! \brief type
    //! \return
    //!
    virtual QVariant type() const;
    virtual MUFormBody&setType(const QVariant &v);

    //!
    //! \brief layout
    //! \return
    //!
    virtual QVariant layout() const;
    virtual MUFormBody&setLayout(const QVariant &v);

    //!
    //! \brief text
    //! \return
    //!
    virtual QString text() const;
    virtual MUFormBody&setText(const QVariant &v);

    //!
    //! \brief sort
    //! \return
    //!
    virtual QVariantHash sort() const;
    virtual MUFormBody&setSort(const QVariant &v);

    //!
    //! \brief controls
    //! \return
    //!
    virtual MUFormControls&controls();

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
    //! \brief items
    //! \return
    //!
    virtual MUFormItems &items();
    virtual MUFormControls &setItems(const QVariant&v);
    virtual MUFormControls &setItems(const ResultValue&lr);

    //!
    //! \brief resultInfo
    //! \return
    //!
    virtual QStm::ResultInfo &resultInfo();
    virtual MUFormControls &setResultInfo(const QStm::ResultInfo&resultInfo);

    //!
    //! \brief setValue
    //! \param v
    //! \return
    //!
    virtual MUFormBody &setValue(const QVariant&v);
    virtual MUFormBody &setValue(const ResultValue&lr);

    //!
    //! \brief setSettings
    //! \param setting
    //! \return
    //!
    Q_INVOKABLE virtual MUFormBody&setSettings(const QVariant&setting);
    Q_INVOKABLE virtual MUFormBody&setFileName(const QString&fileName);

    //!
    //! \brief clear
    //! \return
    //!
    virtual MUFormBody&clear();

private:
    void*p=nullptr;
signals:
    void resourceChanged();
};
