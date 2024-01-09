function updateTooltipPosition(tooltip, chartView) {

  var chartPosition = chartView.mapToItem(root, chartView.mouseArea.mouseX,
                                          chartView.mouseArea.mouseY)
  var mouseXGlobal = chartPosition.x
  var mouseYGlobal = chartPosition.y - tooltip.height / 2
  if (mouseXGlobal > chartView.width / 2)
    tooltip.x = mouseXGlobal - tooltip.width - 20
  else
    tooltip.x = mouseXGlobal + 20

  tooltip.y = mouseYGlobal
}
