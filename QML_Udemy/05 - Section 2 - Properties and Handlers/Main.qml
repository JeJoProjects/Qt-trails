import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Properties and Handlers Demo")

    property string mFirstName: "Johnny"
    // automatically generated signal for the above property
    onMFirstNameChanged: {
        console.log("The first name is changed to "+ mFirstName)
    }

    Rectangle {
        id: rect1
        width: rootWindow.width * 0.3
        height: rootWindow.height * 0.3
        color: "greenyellow"
        border.color: "black"
        border.width: 3
        anchors.centerIn: parent

        MouseArea {
            anchors.fill: parent
            onClicked: {
                mFirstName = "Boy"
            }
        }
    }
    Component.onCompleted: {
        console.log("The first name is "+ mFirstName)
    }
}
