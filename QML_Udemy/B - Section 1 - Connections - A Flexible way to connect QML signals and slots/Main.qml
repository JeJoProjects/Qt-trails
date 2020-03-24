import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Connections - A Flexible way to connect QML signals and slots Demo")

    Row {
        id: row1
        anchors.centerIn: parent
        spacing: 10

        Rectangle {  // Red - Rectangle
            id: rect1
            width: rootWindow.width * 0.1
            height: rootWindow.height * 0.1
            color: "red"
            radius: 25
            border.color: "black"
            border.width: 3

            MouseArea {
                id: redRectMouseArea
                anchors.fill: rect1
                onClicked: {
                    console.log("The red rectangle has been clicked");
                }
            }
        }

        Rectangle {  // Green - Rectangle
            id: rect2
            width: rootWindow.width * 0.1
            height: rootWindow.height * 0.1
            color: "green"
            radius: 25
            border.color: "black"
            border.width: 3

            Connections {  // Connections to the Red - Rectangle
                target: redRectMouseArea
                onClicked: {
                    console.log("The green rectangle responding");
                }
            }
        }

        Rectangle {  // Blue - Rectangle
            id: rect3
            width: rootWindow.width * 0.1
            height: rootWindow.height * 0.1
            color: "blue"
            radius: 25
            border.color: "black"
            border.width: 3

            Connections {  // Connections to the Red - Rectangle
                target: redRectMouseArea
                onClicked: {
                    console.log("The blue rectangle responding");
                }
            }
        }
    }
}
