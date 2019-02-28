import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Virtual List")

    ListView {
        id: nameListId
        anchors.fill: parent
        width: 50
        highlightFollowsCurrentItem: false
        model: nameModel
        delegate:  RowLayout {
            Text { text: "Name: " + model.firstName }
            CheckBox { checked: model.active; text: "Active" }
        }
    }

    Button {
        id: topBtnId
        text: "Top"

        anchors.right: nameListId.right
        onClicked: nameListId.positionViewAtBeginning()
    }

    Button {
        text: "Bottom"

        anchors.right: nameListId.right
        anchors.top: topBtnId.bottom

        onClicked: nameListId.positionViewAtEnd()
    }
}
