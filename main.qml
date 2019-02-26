import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Virtual List")

    ListView {
        anchors.fill: parent

        model: nameModel
        delegate:  Text { text: "Name: " + firstName }
    }
}
