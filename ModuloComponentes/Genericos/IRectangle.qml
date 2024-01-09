import QtQuick 2.15
import ModuloConstantes 1.0
import QtQuick.Effects

Item {
  id: root

  property bool shadowOn: true
  property alias radius: rec.radius
  property alias color: rec.color
  property int timeAnimationColor: 1000
  property string shadowColor: "black"
  property double shadowOpacity: 0.4

  Rectangle {
    id: rec
    anchors.fill: parent
    radius: 10
    color: Cores.colorContainer

    layer.enabled: shadowOn
    layer.effect: MultiEffect {
      shadowEnabled: true
      shadowBlur: 0.6
      shadowHorizontalOffset: 0
      shadowVerticalOffset: 0
      shadowColor: shadowColor
      shadowOpacity: shadowOpacity
    }

    Behavior on color {
      ColorAnimation {
        duration: timeAnimationColor
      }
    }
  }
}
