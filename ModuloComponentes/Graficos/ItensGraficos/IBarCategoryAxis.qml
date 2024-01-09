import QtQuick 2.15
import ModuloConstantes 1.0
import QtCharts

BarCategoryAxis {
  id: barCategories
  labelsColor: Cores.colorTextAxis
  labelsBrush: Qt.color(Cores.colorTextAxis)
  labelsFont.bold: true
  labelsFont.weight: Font.PreferNoHinting
  labelsFont.family: "Roboto"
  color: Cores.colorGridLine
  gridLineColor: Cores.colorGridLine

  Behavior on color {
    ColorAnimation {
      duration: 1000 // Duração da animação em milissegundos
    }
  }

  Behavior on gridLineColor {
    ColorAnimation {
      duration: 1000 // Duração da animação em milissegundos
    }
  }
}
