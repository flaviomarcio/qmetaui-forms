QT += core
QT += quickcontrols2
QT += gui
QT += xml
QT += qml
QT += quick
QT += svg
QT += network
QT += websockets
QT += positioning
QT += location

HEADERS += \
    $$PWD/mu_form_body.h \
    $$PWD/mu_form_consts.h \
    $$PWD/mu_form_control_cache.h \
    $$PWD/mu_form_crud.h \
    $$PWD/mu_form_filter.h \
    $$PWD/mu_form_filters.h \
    $$PWD/mu_form_global.h \
    $$PWD/mu_form_header.h \
    $$PWD/mu_form_headers.h \
    $$PWD/mu_form_items.h \
    $$PWD/mu_form_link.h \
    $$PWD/mu_form_links.h \
    $$PWD/mu_form_macro.h \
    $$PWD/mu_form_object_model.h \
    $$PWD/mu_form_register.h \
    $$PWD/mu_form_request_model.h \
    $$PWD/mu_form_runner.h \
    $$PWD/mu_form_setting.h \
    $$PWD/mu_form_types.h \
    $$PWD/mu_form_controls.h \
    $$PWD/private/p_mu_form_link_base.h

SOURCES += \
    $$PWD/mu_form_body.cpp \
    $$PWD/mu_form_control_cache.cpp \
    $$PWD/mu_form_crud.cpp \
    $$PWD/mu_form_filter.cpp \
    $$PWD/mu_form_filters.cpp \
    $$PWD/mu_form_header.cpp \
    $$PWD/mu_form_headers.cpp \
    $$PWD/mu_form_items.cpp \
    $$PWD/mu_form_link.cpp \
    $$PWD/mu_form_links.cpp \
    $$PWD/mu_form_controls.cpp \
    $$PWD/mu_form_object_model.cpp \
    $$PWD/mu_form_register.cpp \
    $$PWD/mu_form_request_model.cpp \
    $$PWD/mu_form_runner.cpp \
    $$PWD/mu_form_setting.cpp \
    $$PWD/private/p_mu_form_link_base.cpp
