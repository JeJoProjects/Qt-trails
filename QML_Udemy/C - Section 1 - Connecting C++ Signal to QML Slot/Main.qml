import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.5

Window {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Connecting C++ Signal to QML Slot Demo")

    // defining the var mFont for the text
    property var mFont: Qt.font({family:"Helvetica", pointSize: 24, bold: true});

    // connects the signals coming from C++ to the slots in QML
    Connections {
        target: CppSignalSender
        // following will capture the signal that has been sent from the C++.
        // remeber: the signal should be callQml in C++ class
        onCallQml : {
            console.log("This is QML: CppSignalSender::callQml(QString arg) signal is cought");
            textId.text = arg;
        }

        // connects the C++ signal(i.e. cppTimer) to the slot rectText.text)
        onCppTimer : {
            console.log("Calling from onCppTimer");
            rectText.text = value;
        }
    }

    Column {
        id: col1
        anchors.centerIn: parent
        spacing: 10

        Rectangle { // Rectangle to get the updates from C++ slot(i.e. lambda function)
            id: rect
            width: rootWindow.width * 0.3
            height: rootWindow.height * 0.3
            color: "red"
            radius: 30
            border.color: "black"
            border.width: 3
            anchors.alignWhenCentered: parent

            Text {
                id: rectText
                text: qsTr("0")
                anchors.centerIn: parent
                color: "white"
                font: mFont
            }
        }

        Button {  // Button to call the C++ class's slot(or method)
            id: button1
            text: qsTr("Call C++ Slot")
            anchors.alignWhenCentered: parent
            // following signal from QML(i.e. onClicked:) will calls the function
            // (i.e. slot from the C++ class)
            onClicked: {
                CppSignalSender.cppSlot();
            }
        }

        Text {
            id: textId
            text: qsTr("Some text")
            font:  mFont
            color: "steelblue"
            anchors.alignWhenCentered: parent
        }
    }
}
