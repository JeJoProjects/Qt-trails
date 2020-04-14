import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("A tour of Qt Quick basic Elements Demo")

    // Item element
    Item {
        id: containerItemId
        x : 150
        y : 50

        width: 400
        height: 300

        // Rectangle element
        Rectangle {
            anchors.fill: parent
            color: "beige"
            border.color: "black"
            border.width: 3
        }

        Rectangle { // rectangle - 1
            id: rect1
            x: 0
            y: 10
            width : 50
            height: 50
            color: "red"
            border.color: "black"
            border.width: 2

            MouseArea {
                anchors.fill: parent
                onClicked: {

                }
            }
        }

        Rectangle { // rectangle - 2
            id: rect2
            x: 60
            y: 10
            width : rect1.width
            height: rect1.height
            color: "green"
            border.color: "black"
            border.width: 2

            MouseArea {
                anchors.fill: parent
                onClicked: {

                }
            }
        }

        Rectangle { // rectangle - 3
            id: rect3
            x: 120
            y: 10
            width : rect1.width
            height: rect1.height
            color: "blue"
            border.color: "black"
            border.width: 2

            MouseArea {
                anchors.fill: parent
                onClicked: {

                }
            }
        }

        Rectangle { // rectangle - 4
            id: rect4
            x: 180
            y: 10
            width : rect1.width
            height: rect1.height
            color: "magenta"
            border.color: "black"
            border.width: 2

            MouseArea {
                anchors.fill: parent
                onClicked: {

                }
            }
        }

        // Text element
        Text {
            id: text1
            x: 70
            y: 100
            text: qsTr("This is a bold text")
            font.family: "Helvetica"
            font.pointSize: 24
            font.bold: true
            color: "red"
        }

        // Image element
        Image {
            id:  img1
            x:10
            y:150
            width: 100
            height: 100
            // source: "file:img.jpg"  // way - 1
            // source: "img.jpg"       // way - 2
            // way - 3
            // source: "file: ///C:/Z Drive/C++/Qt-trails/QML_Udemy/06 - Section 3 - A tour of Qt Quick basic Elements/img.jpg"
            // way - 4
            source: "https://doc-snapshots.qt.io/qt5-5.9/images/windows-xp-style.png"
        }
    }
}
