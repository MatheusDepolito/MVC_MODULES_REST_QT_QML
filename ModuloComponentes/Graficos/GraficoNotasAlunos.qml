import QtQuick 2.15
import "./ItensGraficos"
import QtCharts
import ModuloConstantes 1.0
import "Js.js" as Js
import QtQuick.Layouts

Item {
  id: root
  anchors.fill: parent
  property alias valorNotas: notaBarSet.values
  property alias categories: barSeries.barCategoriesY.categories
  property alias raValue: raAluno.ra

  IChartView {
    id: chartView
    anchors.fill: parent

    IHorizontalBarSeries {
      id: barSeries
      barCategoriesY.labelsFont.pointSize: 7
      barCategoriesY.truncateLabels: false

      BarSet {
        id: notaBarSet
        label: "Nota"
        color: Cores.colorMuitoBom
        borderColor: Cores.colorBordaBarras
        values: [10, 20, 30, 40, 50, 60, 70, 10, 20]
      }
    }
  }
  IToolTip {
    id: tooltip
    titulo.text: "Notas"

    GridLayout {
      anchors.top: parent.titulo.bottom
      anchors.bottom: parent.bottom
      anchors.right: parent.right
      anchors.left: parent.left
      anchors.leftMargin: 10
      anchors.rightMargin: 10
      anchors.bottomMargin: 10
      anchors.topMargin: 5
      columns: 1
      rows: 2

      Text {
        id: raAluno
        property string ra
        text: qsTr("Ra: " + ra)
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.maximumHeight: parent.height / 2
        color: Cores.colorTextToolTip
        font.bold: true
        elide: Text.ElideRight
      }

      ItemToolTip {
        id: notas
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.maximumHeight: parent.height / 2
        cor: Cores.colorMuitoBom
      }
    }
  }

  Connections {
    target: barSeries

    function onHovered(status, index, barset) {
      tooltip.opacity = status ? 1 : 0
      raAluno.ra = barSeries.barCategoriesY.categories[index]
      notas.value = notaBarSet.values[index]
      notas.cor = notaBarSet.color

      if (status) {
        Js.updateTooltipPosition(tooltip, chartView)
        chartView.mouseArea.cursorShape = Qt.PointingHandCursor
      } else {
        chartView.mouseArea.cursorShape = Qt.ArrowCursor
      }
    }
  }
}
