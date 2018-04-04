import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.3
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3

Window {
    id: loginWindow
    width: 350
    height: 500
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width

    visible: true

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Column {
            id: column
            spacing: 20
            anchors.fill: parent

            Image {
                id: avatarImage
                width: 150
                height: 150
                anchors.top: parent.top
                anchors.topMargin: 25
                anchors.horizontalCenter: parent.horizontalCenter
                source: "images/login_avatar.jpg"
            }

            Rectangle{
                id: userInput
                color: "#ded8d8"
                height: childrenRect.height+5
                width: childrenRect.width+20
                radius: 5

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: avatarImage.bottom
                anchors.topMargin: 50

                TextInput {
                    width: 200
                    height: 20
                    text: qsTr("Użytkownik")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                }
            }

            Rectangle{
                id: passInput
                color: "#ded8d8"
                height: childrenRect.height+5
                width: childrenRect.width+20
                radius: 5

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: userInput.bottom
                anchors.topMargin: 25

                TextInput {
                    width: 200
                    height: 20
                    text: qsTr("Hasło")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                    echoMode: TextInput.Password
                }
            }

            Rectangle {
                id: rectangle
                height: 100
                color: "#d0fdd0"
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.bottom: parent.bottom


                RoundButton {
                    id: roundButton
                    width: 100
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    radius: 25
                    text: "Zaloguj"
                    onClicked:{
                        myEngineControl.load("qrc:/MainWindow.qml")
                        loginWindow.close()
                    }
                }
            }

        }
    }

}
