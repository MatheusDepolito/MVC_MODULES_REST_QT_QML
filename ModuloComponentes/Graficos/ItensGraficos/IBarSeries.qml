import QtQuick
import QtCharts
import QtQuick.Controls

BarSeries {
  id: series

  property alias barCategoriesY: barCategoriesY
  property alias barCategoriesX: barCategoriesX

  axisY: IValueAxis {
    id: barCategoriesY
  }

  axisX: IBarCategoryAxis {
    id: barCategoriesX
  }
}
