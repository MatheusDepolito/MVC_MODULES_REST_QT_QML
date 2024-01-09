import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15
import ModuloConstantes 1.0

Item {
  id: tooltip
  width: 120
  height: 80
  opacity: 0
  property alias titulo: titulo

  Behavior on opacity {
    PropertyAnimation {
      duration: 200
    }
  }

  Behavior on x {
    PropertyAnimation {
      duration: 600
      easing.type: Easing.OutQuad
    }
  }

  Behavior on y {
    PropertyAnimation {
      duration: 600
      easing.type: Easing.OutQuad
    }
  }

  Rectangle {
    anchors.fill: parent
    radius: 10
    color: Cores.colorContainer
    border.color: Qt.lighter(color)
  }

  Text {
    id: titulo
    anchors.top: parent.top
    anchors.right: parent.right
    anchors.left: parent.left
    anchors.margins: 10
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    clip: true
    text: qsTr("")
    color: Cores.colorTextToolTip
    font.bold: true
    elide: Text.ElideRight
  }
} //  MyToolTip {//    titulo.text: "Teste"//    GridLayout {//      anchors.top: parent.titulo.bottom//      anchors.bottom: parent.bottom
//      anchors.right: parent.right
//      anchors.left: parent.left
//      anchors.leftMargin: 10
//      anchors.rightMargin: 10
//      anchors.bottomMargin: 10
//      anchors.topMargin: 5
//      columns: 2

//      MyItemToolTip {
//        id: bim1Medias
//        Layout.fillHeight: true
//        Layout.fillWidth: true
//        Layout.maximumHeight: parent.height / 2
//        cor: "red"
//        value: "9,5"
//      }
//      MyItemToolTip {
//        id: bim2Medias
//        Layout.fillHeight: true
//        Layout.fillWidth: true
//        Layout.maximumHeight: parent.height / 2
//        cor: "yellow"
//        value: "9,5"
//      }
//    }
//  }

