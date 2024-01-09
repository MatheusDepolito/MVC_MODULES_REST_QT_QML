cmake_minimum_required(VERSION 3.16)

project(DashboardEducacional VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOGEN_PARALLEL AUTO)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Charts Core Qml Network)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appDashboardEducacional
    main.cpp
)

list(APPEND QML_FILES Main.qml MainWindow.qml)

list(APPEND SOURCES_FILES Utils/utils.h Utils/utils.cpp Utils/Tipos.h Utils/RestAccessManager.h Utils/RestAccessManager.cpp Controllers/MainController.h Controllers/MainController.cpp)

set(icon_files)
foreach(icon IN ITEMS baixo barChart1 grid more-vertical calendar graduation cima config home left gridDots minus moon Nao notify refresh resize right Sim square sun x)
    set(icon_ico "Icones/${icon}.ico")
    set(icon_svg "Icones/${icon}.svg")

    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${icon_ico})
        list(APPEND icon_files "${icon_ico}")

    elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${icon_svg})
        list(APPEND icon_files "${icon_svg}")
    endif()
endforeach()

qt_add_resources(appDashboardEducacional "Icones" FILES
    ${icon_files}
)

qt_add_qml_module(appDashboardEducacional
    URI DashboardEducacional
    VERSION 1.0
    QML_FILES
        ${QML_FILES}
    SOURCES
        ${SOURCES_FILES}
)

add_subdirectory(ModuloPedagogico)
add_subdirectory(ModuloMatriculas)
add_subdirectory(ModuloConstantes)
add_subdirectory(ModuloComponentes)
set_target_properties(appDashboardEducacional PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appDashboardEducacional
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appDashboardEducacional
    PRIVATE
    Qt6::Quick
    Qt6::Charts
    Qt6::Qml
    Qt6::Core
    Qt6::Network
    ModuloMatriculasplugin
    ModuloPedagogicoplugin
    ModuloConstantesplugin
    ModuloComponentesplugin
)

include(GNUInstallDirs)
install(TARGETS appDashboardEducacional
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
