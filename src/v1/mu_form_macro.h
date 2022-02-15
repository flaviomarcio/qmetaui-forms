#pragma once

#define QMETAUI_FORM_DECLARE_TYPE(_MACRO_VALUE_)\
Q_INVOKABLE virtual QVariant defaultType()const{\
    static const QVariant ___return=_MACRO_VALUE_;\
    return ___return;\
}

#define QMETAUI_FORM_DECLARE_LAYOUT(_MACRO_VALUE_)\
Q_INVOKABLE virtual QVariant defaultLayout()const{\
    static const QVariant ___return=_MACRO_VALUE_;\
    return ___return;\
}
