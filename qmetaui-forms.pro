TARGET = QMetaUiForms
TEMPLATE = lib

CONFIG += c++17
CONFIG += silent

CONFIG+=qmltypes
QML_IMPORT_NAME = QMetaUiForms
QML_IMPORT_MAJOR_VERSION = 1

include($$PWD/../qstatusbar/qstatusbar.pri)
include($$PWD/../qtinyaes/qtinyaes.pri)
include($$PWD/../qstm/qstm.pri)
include($$PWD/../qrpc/src/qrpc-client.pri)
include($$PWD/../qmetaui/qmetaui.pri)
include($$PWD/qmetaui-forms.pri)
