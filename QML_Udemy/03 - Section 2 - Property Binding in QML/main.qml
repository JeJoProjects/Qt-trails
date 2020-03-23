import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Property Binding in QML")

    Rectangle {  // Rectangle - red color
        id: redRectangle
        width: 50
        height: width * 1.5
        color: "red"
        anchors.centerIn: parent
    }

    Rectangle { // button - 1
        id: button1
        x: rootWindow.width - width - 10
        y: 10
        width: parent.width * 0.15
        height: parent.height * 0.1
        gradient: "NightFade"
        border.color: "black"
        border.width: 3
        radius: 40

        MouseArea {
            id: button1MouseArea
            anchors.fill: parent
            Text {
                id: button1Name
                text: qsTr("Button - 1")
                font.bold: true
                font.pointSize: button1.height * 0.2
                anchors.centerIn: button1MouseArea
            }
            onClicked: {
                redRectangle.width += 10
                console.log("Current (width, height) of redRectangle: (" + redRectangle.width + ", " + redRectangle.height + ")");
            }
        }
    }

    Rectangle { // button - 2
        id: button2
        x: rootWindow.width - width - 10
        y: button1.y + button1.height + 10
        width: parent.width * 0.15
        height: parent.height * 0.1
        gradient: "NightFade"
        border.color: "black"
        border.width: 3
        radius: 40

        MouseArea {
            id: button2MouseArea
            anchors.fill: parent
            Text {
                id: button2Name
                text: qsTr("Button - 2")
                font.bold: true
                font.pointSize: button2.height * 0.2
                anchors.centerIn: button2MouseArea
            }
            onClicked: {
                // break the binding of the propert of the redRectangle
                // redRectangle.height = 100
                // Qt Binding
                redRectangle.height = Qt.binding(function() {
                    return redRectangle.width * 1.8;
                });
                console.log("Current (width, height) of redRectangle: (" + redRectangle.width + ", " + redRectangle.height + ")");
            }
        }
    }
}

