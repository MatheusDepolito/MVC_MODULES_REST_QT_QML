qt_add_library(ModuloComponentes STATIC)

set_target_properties(ModuloComponentes PROPERTIES AUTOMOC ON)
target_link_libraries(ModuloComponentes PRIVATE Qt6::Quick Qt6::Core ModuloConstantesplugin)

list(APPEND MODULE_QML_FILES Genericos/SimpleButton.qml Genericos/IconButton.qml)

list(APPEND MODULE_SOURCES_FILES)


qt_add_qml_module(ModuloComponentes
    URI ModuloComponentes
    VERSION 1.0
#    RESOURCE_PREFIX /md.com/imports
    QML_FILES
        ${MODULE_QML_FILES}
    SOURCES
        ${MODULE_SOURCES_FILES}
        QML_FILES Genericos/Icon.qml
        QML_FILES Genericos/IComboBox.qml
        QML_FILES Genericos/IRectangle.qml
        QML_FILES Genericos/WindowDragHandler.qml
        QML_FILES Genericos/IOverlay.qml
        QML_FILES Graficos/ItensGraficos/IBarCategoryAxis.qml
        QML_FILES Graficos/ItensGraficos/IBarSeries.qml
        QML_FILES Graficos/ItensGraficos/IChartView.qml
        QML_FILES Graficos/ItensGraficos/IHorizontalBarSeries.qml
        QML_FILES Graficos/ItensGraficos/IHorizontalStackedBarSeries.qml
        QML_FILES Graficos/ItensGraficos/ItemToolTip.qml
        QML_FILES Graficos/ItensGraficos/IStackedBarSeries.qml
        QML_FILES Graficos/ItensGraficos/IToolTip.qml
        QML_FILES Graficos/ItensGraficos/IValueAxis.qml
        QML_FILES Graficos/Js.js
        QML_FILES Graficos/GraficoNotasAlunos.qml

)


