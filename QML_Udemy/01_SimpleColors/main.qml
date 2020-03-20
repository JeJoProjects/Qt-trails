import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Text {
        id: textToShow
        text: "Hello World"
        color: "blue"
        font.pointSize: 32
        anchors.centerIn: parent
    }

}
