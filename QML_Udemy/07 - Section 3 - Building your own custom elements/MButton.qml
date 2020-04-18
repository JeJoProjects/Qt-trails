import QtQuick 2.14

// defining own Button Component
Item
{
    id: rootButton

    // property aliasing - to specify seperate text messages
    property alias buttonText: buttonRectangleText1.text

    // to expose the width and height
    width: buttonRectangle.width
    height: buttonRectangle.height

    // signal to specify the button click actions
    signal buttonClicked

    Rectangle
    {
        id: buttonRectangle
        width: buttonRectangleText1.implicitWidth + 20
        height: buttonRectangleText1.implicitHeight + 20
        color: "yellow"
        border { color: "blue"; width: 3 }

        Text {
            id: buttonRectangleText1
            anchors.centerIn: buttonRectangle
            text: "Button with arbitary width"
        }

        MouseArea {
            anchors.fill: buttonRectangle
            onClicked: {
                rootButton.buttonClicked()
                // console.log("Clicked ON: " + buttonRectangleText1.text)
            }
        }
    }
}


