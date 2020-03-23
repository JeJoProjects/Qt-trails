import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.VirtualKeyboard 2.14

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Basictypes Demo")

    // basic data-types
    property string mString: "Hello world"// "https://www.qt.io/"
    property int mInt: 50
    property bool mBool: false
    property double mDouble: 80.5
    property url mUrl: "https://www.qt.io/"

    // var data-types
    property var aNumber: 100
    property var aBool: false
    property var aString: "Hello world!"
    property var anotherString: String("#FF008800")
    property var aColor: Qt.rgba(0.2, 0.3, 0.4, 1)
    property var aRect: Qt.rect(17, 10, 26, 100)
    property var aPoint: Qt.point(10, 10)
    property var aSize: Qt.size(10, 10)
    property var aVector3d: Qt.vector3d(100, 100, 100)
    property var anArray: [1, 2, 3, "four", "five", (function() { return "six"; })]
    property var anObject: { "foo": 10, "bar": 20 }
    property var aFunction: (function() { return "one"; })

    // other data-types
    property var mFont: Qt.font({family: "Consolas", pointSize: 30, bold: true})
    property date mDate: "2020-03-10"

    Rectangle {
        id: rect1
        width: parent.width * 0.5
        height: parent.height * 0.5 + mInt
        gradient: "NightFade"
        border.color: "black"
        border.width: 3
        anchors.centerIn: parent

        Text {
            id: textArea
            text: mString // qsTr("Hello World")
            color: aColor //"black"
            // font.bold: true
            // font.pointSize: : 20
            font: mFont
            anchors.centerIn:parent
        }
    }


    Component.onCompleted: {
        console.log("The value of mString is: " + mString);
        console.log("The value of mInt is: " + mInt);
        console.log(mBool ? "It is TRUE case!" : "It is FALE case");
        console.log("The value of mDouble is: " + mDouble);
        console.log("The value of mUrl is: " + mUrl);
        console.log(mString === mUrl ? "They are equal!" : "They are NOT equl");

        // var outputs
        console.log("--------------------Playing with the var types --------------")
        console.log("The value of aNumber is: " + aNumber);
        console.log("The value of aBool is: " + aBool);
        console.log("The value of aString is: " + aString);
        console.log("The value of anotherString is: " + anotherString);
        console.log("The components of aRect are: x = " + aRect.x + " y = " + aRect.y+ " width = " + aRect.width+ " height = " + aRect.height);

        // ---
        // anArray and outputting the elements of it
        console.log("The length of the array is: " + anArray.length);
        anArray.forEach(function(value, index) { // lambda function in QML
            console.log("The " + index + "th element of the array is: "
                        + (index === 5 ? value() : value));
        });
        // normal loops
        console.log("Outputing the elements using a for-loop");
        for(var idx = 0; idx < anArray.length; ++idx)
        {
            console.log("The " + idx + "th element of the array is: "
                        + (idx === 5 ? anArray[idx]() : anArray[idx]));
        }
        console.log("Calling the Lambda function: " + aFunction());

        // other data-types
        console.log("The date is: " + mDate);

    }

    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        states: State {
            name: "visible"
            when: inputPanel.active
            PropertyChanges {
                target: inputPanel
                y: window.height - inputPanel.height
            }
        }
        transitions: Transition {
            from: ""
            to: "visible"
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "y"
                    duration: 250
                    easing.type: Easing.InOutQuad
                }
            }
        }
    }
}
