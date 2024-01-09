import QtQuick 2.15
import QtQuick.Controls 2.15

DragHandler {
  enabled: true
  required property ApplicationWindow dragWindow

  target: null
  onActiveChanged: {
    if (active)
      dragWindow.startSystemMove()
  }
}
