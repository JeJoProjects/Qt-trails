import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.5

Window {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Calling C++ from QML  ContextProperty Demo")

    Column {
        spacing: 10
        anchors.centerIn: parent

        Button { // button for calling C++ methonds from CppWorker
            id:button1
            highlighted: true
            text: "Calll C++ Mentod"
            font.bold: true


            onClicked: {
                Worker.regularMethod()
                Worker.cppSlot()
            }
        }

        Rectangle { // button for C++ methond from CppWorker
            id: rect1
            width: rect1Button.implicitWidth + 20
            height: rect1Button.implicitHeight + 20
            color: "beige"
            radius: 10
            border.color: "black"
            border.width: 3

            Text {
                id: rect1Button
                text: qsTr(Worker.regularMethodWithReturn("JeJo", 28))
                font.bold: true
                font.pointSize: 12
                anchors.centerIn: parent
            }
        }
    }

    // creating a Other Item here#
    Other {

    }
}
