import QtQuick 2.15
import QtQuick.Controls 2.15
import QtReforce.Meta.Forms 0.0
import "qrc:/QMetaUI/Form/Core"
//import "qrc:/moduleDemo"

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Tabs")

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page{
            MCFormRunner {
                anchors.fill: parent
                source: "file:///home/debian/git/github/qtreforce/qtreforce-sdk/src/3rdparty/qmetaui-forms/examples/register/QOption600.qml"
            }
        }

        Page{
            MCFormRunner {
                anchors.fill: parent
                source: "file:///home/debian/git/github/qtreforce/qtreforce-sdk/src/3rdparty/qmetaui-forms/examples/register/QOption600.qml"
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("QOption600")
        }
        TabButton {
            text: qsTr("QOption601")
        }
    }
}
