import QtCharts

HorizontalBarSeries {
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
