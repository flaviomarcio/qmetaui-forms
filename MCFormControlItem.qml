import QtQuick 2.14

Item {
    id:control
    signal show()
    signal close()
    signal objectReload()

    signal dataNew(var data)
    signal dataSearch(var data)
    signal dataEdit(var data)
    signal dataRemove(var data)
    signal dataPost(var data)
    signal dataClear(var data)
}
