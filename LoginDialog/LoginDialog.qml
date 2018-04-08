import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls 1.4
import Qt.labs.calendar 1.0

Window {
    id: loginWindow


    function login(){
        var username = userField.textInput.text
        var password = passwordField.textInput.text
        var database = comboModel.get(dbComboBox.currentIndex).value
        //Przeniesc wewnatrz if po znalezieniu bledu
        //myEngineControl.login(database,"Flowair test",username,password)
        if(1==1)
        {
            myEngineControl.load("qrc:/MainWindow.qml")
            loginWindow.close()
        }
        myEngineControl.isOpen()
    }

    width: 350
    height: 500
    color: "#fdfdfd"
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width

    visible: true

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        Image {
            id: avatarImage
            width: 150
            height: 150
            anchors.top: parent.top
            anchors.topMargin: 30
            anchors.horizontalCenter: parent.horizontalCenter
            source: "../images/login_avatar.jpg"
        }

        MyInputField{
            id: userField
            anchors.top: avatarImage.bottom
            anchors.topMargin: 50
            label.text: "Użytkownik"
            textInput.text: "GMICKOWSKI"
        }

        MyInputField{
            id: passwordField
            anchors.top: userField.bottom
            anchors.topMargin: 50
            label.text: "Hasło"
            textInput.echoMode: TextInput.Password
            textInput.text: "GMi2016!"
        }

        Label {
            id: labelID
            anchors.left: dbComboBox.left
            anchors.bottom: dbComboBox.top
            anchors.bottomMargin: 5
            text: qsTr("Baza")
        }
        ComboBox {
            id: dbComboBox
            x: 105
            y: 334
            width: 220
            height: 30

            anchors.horizontalCenter: parent.horizontalCenter

            textRole: "key"
            model: ListModel {
                id: comboModel
                ListElement { key: "Baza produkcyjna"; value: "BPSC" }
                ListElement { key: "Baza testowa"; value: "TEST" }
            }
        }



        Rectangle {
            id: rectangle
            height: 100
            color: "#e1fee1"
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.bottom: parent.bottom


            RoundButton {
                id: roundButton
                x: 125
                width: 200
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                radius: 25
                text: "Zaloguj"
                onClicked:{
                     loginWindow.login()
                }
            }
        }


    }

}
