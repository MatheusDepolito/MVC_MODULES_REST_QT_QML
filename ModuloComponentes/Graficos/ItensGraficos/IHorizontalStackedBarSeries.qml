import QtQuick
import QtCharts
import Constantes 1.0
import QtQuick.Controls

HorizontalStackedBarSeries {
  id: series

  property alias barCategoriesY: barCategoriesY
  property alias barCategoriesX: barCategoriesX

  axisY: IBarCategoryAxis {
    id: barCategoriesY
  }

  axisX: IValueAxis {
    id: barCategoriesX
  }
}
