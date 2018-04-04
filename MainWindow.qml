import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import Qt.labs.calendar 1.0

ApplicationWindow {

    Loader {id: pageLoader }

    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Database QML tools")

    menuBar: MenuBar {
        Menu {
            title: "Plik"

            MenuItem {
                text: "Zmień użytkownika"
                shortcut: "Ctrl+L"
            }

            MenuSeparator{}

            MenuItem {
                text: "Zakończ"
                shortcut: "Ctrl+E"
                onTriggered: window.close()
            }
        }

        Menu {
            title: "Edycja"
        }

        Menu {
            title: "Pomoc"
        }
    }

    statusBar: StatusBar {
        RowLayout {
            anchors.fill: parent
            Label {text: "Aplikacja WAMM serwer"}
        }

    }

    TabView {
        anchors.fill: parent

        MouseArea {
            anchors.fill: parent

            Text {
                id: text1
                anchors.verticalCenterOffset: 20
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Przykładowa tabela danych")
                font.pixelSize: 12
                }
            TableView {
                anchors.top: text1.bottom
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
                id: list_view1
                TableViewColumn  {
                    role: "NUMER_KATALOGOWY"
                    title: "NUMER_KATALOGOWY"
                    width: 150
                }
                TableViewColumn  {
                    role: "INDEKS"
                    title: "INDEKS"
                    width: 300;
                }
                model: myModel
            }
        }
    }


}


