import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.3

Rectangle {
    width: 350
    height: 500

    Column {
        id: column
        spacing: 20
        anchors.fill: parent

        Image {
            id: image
            width: 150
            height: 150
            anchors.top: parent.top
            anchors.topMargin: 25
            anchors.horizontalCenter: parent.horizontalCenter
            source: "images/login_avatar.jpg"
        }

        TextInput {
            id: textInput
            width: 200
            height: 20
            text: qsTr("Text Input")
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12
        }

        TextInput {
            id: textInput1
            width: 200
            height: 20
            text: qsTr("Text Input")
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 12
        }

        ComboBox {
            id: comboBox
            width: 200
            height: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Rectangle {
            id: rectangle
            height: 100
            color: "#ffffff"
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.bottom: parent.bottom

            RoundButton {
                id: roundButton
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                x: 0
                y: -60
                text: "+"
            }
        }

    }
}

