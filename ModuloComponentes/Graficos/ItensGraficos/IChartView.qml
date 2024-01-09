import QtQuick
import QtCharts
import QtQuick.Controls
import ModuloConstantes 1.0

ChartView {
  id: chartView

  property alias mouseArea: mouseArea

  margins.top: 0
  legend.visible: false
  legend.alignment: Qt.AlignBottom
  margins.bottom: 0
  margins.left: 0
  margins.right: 0
  titleColor: Cores.colorText
  antialiasing: true
  backgroundColor: "transparent"
  legend.labelColor: Cores.colorText
  legend.font.family: "Roboto"
  animationOptions: ChartView.SeriesAnimations

  MouseArea {
    id: mouseArea
    anchors.fill: parent
    hoverEnabled: true

    z: -1
  }
}
