import QtQuick 2.15
import ModuloConstantes 1.0

Item {
  id: root
  signal action
  property alias hovered: hoverHandler.hovered
  property alias titulo: title.text
  property alias borderColor: button.border.color
  property alias radiusB: button.radius

  Rectangle {
    id: button
    radius: 5
    border.color: "transparent"
    width: root.width
    height: root.height
    color: hovered ? Qt.lighter(Cores.colorBackground) : Cores.colorBackground

    Text {
      id: title
      color: Cores.colorText
      anchors.fill: parent
      verticalAlignment: Text.AlignVCenter
      horizontalAlignment: Text.AlignHCenter
      clip: true
    }

    HoverHandler {
      id: hoverHandler
      cursorShape: Qt.PointingHandCursor
    }
    TapHandler {
      onTapped: action()
    }
  }
}
