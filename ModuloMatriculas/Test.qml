import QtQuick 2.15
import ModuloConstantes 1.0

Rectangle {
  color: "red"
  Text {
    anchors.centerIn: parent
    text: Constantes.title
    Component.onCompleted: {
      console.log(Constantes.title)
    }
  }
}
