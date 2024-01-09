qt_add_library(ModuloMatriculas STATIC)

set_target_properties(ModuloMatriculas PROPERTIES AUTOMOC ON)
target_link_libraries(ModuloMatriculas PRIVATE Qt6::Quick ModuloConstantesplugin)

list(APPEND MODULE_QML_FILES)

list(APPEND MODULE_SOURCES_FILES)

qt_add_qml_module(ModuloMatriculas
    URI ModuloMatriculas
    VERSION 1.0
#    RESOURCE_PREFIX /md.com/imports
    QML_FILES
        ${MODULE_QML_FILES}
    SOURCES
        ${MODULE_SOURCES_FILES}
    QML_FILES Test.qml
)


