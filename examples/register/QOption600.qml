import QtQuick 2.15
import QtQuick.Controls 2.15
import "qrc:/QMetaUI/Form/Core"

MCFormControlItem {
    id:control
    TabBar {
        id: tabBar
        anchors{
            top: parent.top
            left: parent.left
            right: parent.right
            margins: 10
        }
        TabButton {
            text: qsTr("Home")
        }
        TabButton {
            text: qsTr("Discover")
        }
        TabButton {
            text: qsTr("Activity")
        }
    }
    SwipeView {
        anchors{
            top: tabBar.bottom
            left: parent.left
            right: parent.right
            bottom: parent.top
        }
        currentIndex: tabBar.currentIndex

        Item {
        }

        Item {
        }

        Item {
        }
    }
}
