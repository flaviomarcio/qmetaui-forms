#pragma once

#include <QtQml>
#include <QMetaUi/Core>
#include "./mu_form_global.h"
#include "./mu_form_types.h"

class Q_QMETAUI_FORM_EXPORT MUFormRegister{
    Q_GADGET
public:
    static void init(QQmlApplicationEngine &engine);

    Q_INVOKABLE explicit MUFormRegister();
    virtual ~MUFormRegister();
};
