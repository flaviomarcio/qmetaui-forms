import QtQuick 2.15
import QtQuick.Controls 2.15
import QtReforce.Meta.Forms 0.0

Item {
    id:control

    property alias source: formLoader.source

    MCFormLoader{
        id:formLoader
    }

    MUFormControlCache{
        id: controlCache
    }


    Component.onCompleted: formLoader.load()

}
