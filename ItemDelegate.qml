import QtQuick 2.9
import QtQuick.Window 2.2

Item {
    id: delegate
    width: delegate.ListView.view.width;
    height: 30
    clip: true
    anchors.margins: 4
    Row {
        anchors.margins: 4
        anchors.fill: parent
        spacing: 4;
        Text {
            text: NUMER_KATALOGOWY
            width: 150
        }
        Text {
            text: INDEKS
            width: 300;
        }

    }
}
