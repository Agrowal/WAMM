import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import Qt.labs.calendar 1.0

ApplicationWindow {

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
            Label {text: "Aplikacja WAMM serwer. Zalogowany jako: "+myEngineControl.currentUserName()}
        }

    }

    TabView {
        anchors.fill: parent
        MouseArea {
            anchors.fill: parent
            SplitView {
                id: splitView
                orientation: Qt.Vertical
                anchors.fill: parent
                Text {
                    id: text1
                    anchors.verticalCenterOffset: 20
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: qsTr("Przykładowa tabela danych")
                    font.pixelSize: 12
                }
                TableView {
                    id: list_view1
                    anchors.top: text1.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    //anchors.bottom: parent.bottom
                    TableViewColumn  {
                        role: "ID"
                        title: "ID"
                        width: 150
                    }
                    TableViewColumn  {
                        role: "INDEKS_CZESCI"
                        title: "INDEKS_CZESCI"
                        width: 150
                    }
                    TableViewColumn  {
                        role: "OPIS"
                        title: "OPIS"
                        width: 300;
                    }
                    model: wersjeWyrobuBrama.resultSet

                    onCurrentRowChanged: {
                        var row = currentRow
                        var id = "2032"
                        mrpStrukturyBrama.find(id)
                    }
                }

                TableView {
                    id: list_view2
                    //anchors.top: text1.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    anchors.bottom: parent.bottom

                    TableViewColumn  {
                        role: "ID_WERSJI_WYROBU"
                        title: "ID_WERSJI_WYROBU"
                        width: 150
                    }
                    TableViewColumn  {
                        role: "INDEKS_SKLADOWY"
                        title: "INDEKS_SKLADOWY"
                        width: 400;
                    }
//                    TableViewColumn  {
//                        role: "NAZWA_UZYTKOWNIKA"
//                        title: "NAZWA_UZYTKOWNIKA"
//                        width: 400;
//                    }
                    model: mrpStrukturyBrama.resultSet
                }


            }
        }


    }
}


