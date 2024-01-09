import QtQuick 2.15
import QtCharts

StackedBarSeries {
  id: series

  property alias barCategoriesY: barCategoriesY
  property alias barCategoriesX: barCategoriesX

  axisX: IBarCategoryAxis {
    id: barCategoriesX
  }
  axisY: IValueAxis {
    id: barCategoriesY
  }
}
