#pragma once

#include <QMetaUi/Core>
#include "./mu_form_global.h"
#include "./mu_form_types.h"

//!
//! \brief The MUFormRunner class
//!
class Q_QMETAUI_FORM_EXPORT MUFormRunner:public QStm::Object
{
    Q_OBJECT
public:
    //!
    //! \brief MUFormRunner
    //! \param parent
    //!
    Q_INVOKABLE explicit MUFormRunner(QObject*parent=nullptr);

    ~MUFormRunner();
private:
    void*p=nullptr;
};
