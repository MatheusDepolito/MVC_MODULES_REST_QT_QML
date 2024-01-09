qt_add_library(ModuloPedagogico STATIC)

set_target_properties(ModuloPedagogico PROPERTIES AUTOMOC ON)
find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Charts Core Qml Network)
target_link_libraries(ModuloPedagogico PRIVATE
    Qt6::Quick
    Qt6::Charts
    Qt6::Qml
    Qt6::Core
    Qt6::Network
    ModuloMatriculasplugin
)



list(APPEND MODULE_QML_FILES)

list(APPEND MODULE_SOURCES_FILES Controllers/TestController.h Controllers/TestController.cpp Models/TestModel.h Models/TestModel.cpp)

qt_add_qml_module(ModuloPedagogico
    URI ModuloPedagogico
    VERSION 1.0
#    RESOURCE_PREFIX /md.com/imports
    QML_FILES
        ${MODULE_QML_FILES}
    SOURCES
        ${MODULE_SOURCES_FILES}
)


