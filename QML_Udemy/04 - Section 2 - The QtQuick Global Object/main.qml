import QtQuick 2.14
import QtQuick.Window 2.14

Window {
    id: rootWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("The QtQuick Global Object Demo")

    // properties
    property var fonts: Qt.fontFamilies()

    Rectangle {
        id: rect1
        width: rootWindow.width * 0.3
        height: rootWindow.height * 0.3
        color: "red"
        border.color: "black"
        border.width: 3
        radius: 50
        anchors.centerIn: parent

        MouseArea {
            id: rect1MouseArea
            anchors.fill: parent
            Text {
                id: rect1Name
                text: qsTr("Quit")
                font.bold: true
                font.pointSize: rect1.height * 0.3
                anchors.centerIn: rect1MouseArea
            }
            onClicked: {
                // Quit the application
                console.log("Qutting the App")
                Qt.quit()  // quit() from Qt globel-object

                // list the available fonts
                for(var idx = 0; idx < fonts.length; ++idx)
                {
                    console.log("["+ idx + "] :" + fonts[idx]);
                }

                // hash the string
                var mName = "Johnny Boy"
                var mNameHash = Qt.md5(mName)
                console.log("The hash of the name is :" + mNameHash)

                // open url externally
                // Qt.openUrlExternally("https://github.com/JeJoProjects")

                // open local files witht default program
                // Qt.openUrlExternally("file:///C:/Z Drive/Videos/Avengers Endgame (2019) [BluRay] [1080p] [YTS.LT]/Avengers.Endgame.2019.1080p.BluRay.x264-[YTS.LT].mp4")

                // capture plateform info
                console.log("The current platform is :" + Qt.platform.os)

                // more under: https://doc.qt.io/qt-5/qml-qtqml-qt.html

            }
        }
    }
}
