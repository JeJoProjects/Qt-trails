import QtQuick 2.14

Rectangle { // Rectangle - 3
    id: rect3
    width: rect3Text1.implicitWidth + 20
    height: rect3Text1.implicitHeight + 20
    color: "yellow"
    border { color: "blue"; width: 3 }

    Text {
        id: rect3Text1
        anchors.centerIn: rect3
        text: "Button with arbitary width"
    }

    MouseArea {
        anchors.fill: rect3
        onClicked: {
            console.log("Clicked ON: " + rect3Text1.text)
        }
    }
}
