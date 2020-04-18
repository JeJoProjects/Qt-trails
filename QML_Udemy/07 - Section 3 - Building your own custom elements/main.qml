import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Building your own custom elements Demo")

    // Column element
    Column
    {
        spacing: 20

        Rectangle {  // Rectangle - 1
            id: rect1
            width: 300
            height: 100
            color: "red"
        }

        Rectangle {  // Rectangle - 2
            id: rect2
            width: 300
            height: 100
            color: "blue"
        }

        Row
        {
            // instances of the MButton qml
            spacing: 10
            MButton {
                buttonText: qsTr("Button - 1")
                onButtonClicked: {
                    console.log("Clicked Button - 1 from main")
                }
            }

            MButton {
                buttonText: qsTr("Button - 2")
                onButtonClicked: {
                    console.log("Clicked Button - 2 from main")
                }
            }
        }
    }

}
