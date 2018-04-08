import QtQuick 2.0
import QtQuick.Controls 2.3

Rectangle{
    property alias label: labelID
    property alias textBackground: textBackgroundID
    property alias textInput: textInputID

    anchors.horizontalCenter: parent.horizontalCenter
    Label {
        id: labelID
        anchors.left: textBackgroundID.left
        anchors.bottom: textBackgroundID.top
        anchors.bottomMargin: 5
        text: qsTr("Użytkownik/Hasło/Baza")
    }
    
    Rectangle{
        id: textBackgroundID
        color: "#ded8d8"
        height: textInputID.height+5
        width: textInputID.width+20
        radius: 5
        
        anchors.horizontalCenter: parent.horizontalCenter
        
        TextInput {
            id: textInputID
            width: 200
            height: 20
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12
        }
    }
}
