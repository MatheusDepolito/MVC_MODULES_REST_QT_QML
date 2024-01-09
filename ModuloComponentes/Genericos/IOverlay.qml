import QtQuick 2.15
import Constantes 1.0

Item {
  id: root
  signal action
  opacity: 0.4

  Rectangle {
    id: rec
    anchors.fill: parent
    color: Cores.colorBackground

    MouseArea {
      anchors.fill: parent

      onClicked: {
        action()
      }
    }
  }
}
