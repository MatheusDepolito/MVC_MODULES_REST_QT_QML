import QtQuick 2.15
import ModuloConstantes 1.0

Item {
  id: root

  property string iconPath: CofreIcones.baixo
  property alias controlListView: listView
  property alias controlTituloComboBox: tituloComboBox

  Rectangle {
    id: containerButtonComboBox
    anchors.fill: parent
    color: "black"

    MouseArea {
      id: mouseArea
      anchors.fill: parent
      cursorShape: Qt.PointingHandCursor
      onClicked: {
        containerListView.visible = !containerListView.visible
        iconPath = (iconPath === CofreIcones.baixo) ? CofreIcones.cima : CofreIcones.baixo
      }
    }

    Text {
      id: tituloComboBox
      font.pointSize: Math.max(parent.height * 0.4, 1)
      color: "white"
      anchors.centerIn: parent
    }

    Item {
      id: containerIcon
      anchors.left: tituloComboBox.right
      anchors.leftMargin: parent.width * 0.02
      height: parent.height
      width: parent.width * 0.15

      Icon {
        width: parent.width
        height: width
        anchors.centerIn: parent
        pathImage: iconPath
      }
    }
  }

  Rectangle {
    id: containerListView
    width: parent.width
    height: 130
    anchors.top: root.bottom
    color: "red"
    visible: false

    ListView {
      id: listView
      width: parent.width
      height: parent.height
      clip: true
    }
  }
}//  MyComboBox {
//    id: comboBox
//    width: 100
//    height: 25
//    z: 100
//    controlTituloComboBox.text: controlListView.currentItem ? controlListView.currentItem.ano : ""

//    controlListView.delegate: Item {
//      property string ano: anoE
//      width: comboBox.controlListView.width
//      height: 30
//      Text {
//        anchors.centerIn: parent
//        text: qsTr(anoE)
//      }
//      MouseArea {
//        anchors.fill: parent
//        cursorShape: Qt.PointingHandCursor
//        onClicked: {
//          if (comboBox.controlListView.currentIndex !== index) {
//            comboBox.controlListView.currentIndex = index
//            var item = comboBox.controlListView.currentIndex
//            MainController.solicitarConsultaTurmas(anoE)
//          }
//        }
//      }
//    }

//    controlListView.model: ListModel {
//      id: listmodel

//      ListElement {
//        anoE: "2023"
//      }
//      ListElement {
//        anoE: "2022"
//      }
//      ListElement {
//        anoE: "2021"
//      }
//    }
//  }

