import QtQuick 2.15
import QtQuick.Layouts 1.15
import ModuloConstantes 1.0

Item {
  property alias value: valueText.text
  property alias cor: recor.color

  Rectangle {
    id: recor
    height: parent.height / 1.5
    width: height
    border.color: Qt.lighter(color)
    anchors.left: parent.left
    anchors.leftMargin: 5
    anchors.verticalCenter: parent.verticalCenter
  }
  Text {
    id: valueText
    color: Cores.colorTextToolTip
    //    text: "0"
    anchors.left: recor.right
    anchors.leftMargin: 10
  }
}
