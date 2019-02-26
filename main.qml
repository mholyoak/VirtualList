import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Virtual List")

    ListView {
        width: 200; height: 250

        model: nameModel
        delegate:  Text { text: "Name: " + firstName }
    }

    /*
    Button {
        id: oneBtn
        text: "One"
        anchors.margins: 10
    }
    Button {
        id: twoBtn
        text: "Two"
        anchors.top: oneBtn.bottom
        anchors.margins: 10
    }
    Button {
        id: threeBtn
        text: "Three"
        anchors.top: twoBtn.bottom
        anchors.margins: 10
    }

    Button {
        id: fourBtn
        text: "Four"
        anchors.left: oneBtn.right
        anchors.margins: 10
    }

    Button {
        id: fiveBtn
        text: "Five"
        anchors.left: twoBtn.right
        anchors.top: fourBtn.bottom
        anchors.margins: 10
    }
*/

    /*
    ListModel {
        id: nameModel
        ListElement { name: "Alice" }
        ListElement { name: "Bob" }
        ListElement { name: "Jane" }
        ListElement { name: "Harry" }
        ListElement { name: "Alice" }
        ListElement { name: "Bob" }
        ListElement { name: "Jane" }
        ListElement { name: "Harry" }
        ListElement { name: "Alice" }
        ListElement { name: "Bob" }
        ListElement { name: "Jane" }
        ListElement { name: "Harry" }
        ListElement { name: "Wendy" }
    }

    Component {
        id: nameDelegate
        Button {
            text: name;
            font.pixelSize: 24
        }
    }

    ListView {
        anchors.fill: parent
        clip: true
        model: nameModel
        delegate: nameDelegate
        header: bannercomponent
    }

    Component {     //instantiated when header is processed
        id: bannercomponent
        Rectangle {
            id: banner
            width: parent.width; height: 50
            gradient: clubcolors
            border {color: "#9EDDF2"; width: 2}
            Text {
                anchors.centerIn: parent
                text: "Club Members"
                font.pixelSize: 32
            }
        }
    }
    Gradient {
        id: clubcolors
        GradientStop { position: 0.0; color: "#8EE2FE"}
        GradientStop { position: 0.66; color: "#7ED2EE"}
    }
    */

    /*
    Text {
        id: myText
        text: qsTr("My Text")
    }

    Text {
        text: qsTr("More Text")
        anchors.left: myText.right
    }

    Rectangle {
        id: rect1
        color: "#00B000"
        width: 80; height: 80
        anchors.top: myText.bottom
    }

    Rectangle {
        color: "steelblue"
        y: 100; width: 80; height: 80
        anchors.top: rect1.bottom
    }
    */
}
