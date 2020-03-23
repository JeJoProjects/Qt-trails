import QtQuick 2.0

Item {
    Component.onCompleted: {
        Worker.cppSlot()
    }
}
