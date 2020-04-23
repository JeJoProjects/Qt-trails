import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Signals and Slots Demo")

    Rectangle {
        id: rectangleId
        width: textId.width + 20
        height: textId.height + 20
        border { color: "black"; width: 3}
        color: "yellow"
        anchors.centerIn: parent

        Text {
            id: textId
            text: qsTr("Button")
            font { bold: true; pointSize: 24 }
            anchors.centerIn: rectangleId
        }
    }

}
