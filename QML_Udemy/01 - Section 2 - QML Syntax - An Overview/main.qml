import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Syntax Demo")

    property string textToShow: "Hello"

    Row {
        id: row1
        anchors.centerIn: parent
        spacing: 20

        Rectangle {   // red Rectangle
            id: rect1
            width: 150
            height: 150
            color: "red"
            radius: 20

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked on the red rectangle")
                    textToShow = "Red"
                }
            }
        }

        Rectangle {   // green Rectangle
            id: rect2
            width: 150
            height: 150
            color: "green"
            radius: 20

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked on the green rectangle")
                    textToShow = "Green"
                }
            }
        }

        Rectangle {   // blue Rectangle
            id: rect3
            width: 150
            height: 150
            color: "blue"
            radius: 20

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked on the blue rectangle")
                    textToShow = "Blue"
                }
            }
        }

        Rectangle {   // circle Rectangle
            id: circle
            width: 150
            height: 150
            color: "yellow"
            radius: 100
            Text {
                id: textId
                anchors.centerIn: parent
                text: textToShow
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("Clicked on CIRCLE")
                    textId.text = "Break the property!"
                }
            }
        }
    }

}
