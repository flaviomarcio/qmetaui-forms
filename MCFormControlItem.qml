import QtQuick 2.15
import QtQuick.Controls 2.15

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
