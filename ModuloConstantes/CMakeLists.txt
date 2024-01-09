qt_add_library(ModuloConstantes STATIC)

set_target_properties(ModuloConstantes PROPERTIES AUTOMOC ON)
target_link_libraries(ModuloConstantes PRIVATE Qt6::Quick Qt6::Core)

list(APPEND MODULE_QML_FILES Constantes.qml Cores.qml CofreIcones.qml )

list(APPEND MODULE_SOURCES_FILES)
set_source_files_properties(Constantes.qml Cores.qml CofreIcones.qml PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

qt_add_qml_module(ModuloConstantes
    URI ModuloConstantes
    VERSION 1.0
#    RESOURCE_PREFIX /md.com/imports
    QML_FILES
        ${MODULE_QML_FILES}
    SOURCES
        ${MODULE_SOURCES_FILES}

)


