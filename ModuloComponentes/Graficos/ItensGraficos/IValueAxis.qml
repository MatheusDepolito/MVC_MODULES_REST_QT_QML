import QtQuick 2.15
import ModuloConstantes 1.0
import QtCharts

ValuesAxis {
  id: barCategories
  //    categories: [1, 3, 5, 6]
  labelFormat: "%d"
  labelsColor: Cores.colorTextAxis
  labelsBrush: Qt.color(Cores.colorTextAxis)
  truncateLabels: false
  labelsFont.pointSize: 7
  labelsFont.bold: true
  labelsFont.family: "Roboto"
  //labelsFont.weight: Font.Light
  gridLineColor: Cores.colorGridLine
  color: Cores.colorGridLine //define a cor da linha x
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
