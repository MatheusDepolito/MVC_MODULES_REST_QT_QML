import QtQuick 2.15

Item {
  id: root
  width: 100
  height: width
  signal action
  property alias imageButton: imageButton
  property alias mouseArea: mouseArea

  Icon {
    id: imageButton
    anchors.centerIn: parent
    height: parent.height / 1.2
    width: height
  }

  MouseArea {
    id: mouseArea
    anchors.fill: parent
    cursorShape: Qt.PointingHandCursor

    onClicked: {
      action()
    }
  }
}
