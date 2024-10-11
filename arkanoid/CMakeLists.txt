cmake_minimum_required(VERSION 3.16)
project(Arkanoid VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("include")
link_directories("src")

set(SOURCE_FILES ${SOURCE_FILES}
    "src/main.cpp"
)

set(HEADER_FILES ${HEADER_FILES}
    "include/qcustomplot.h"
    "include/main_window.h"
    "include/functions_draw.h"
    "include/qrect_draw.h"
    "include/graphic_object.h"
    "include/functions_select_test.h"
    "include/qrect_select_test.h"
    "include/brick.h"
    "include/brick_draw.h"
    "include/brick_select_test.h"
)

set(SOURCE_FILES ${SOURCE_FILES}
    "src/qcustomplot.cpp"
    "src/main_window.cpp"
    "src/qrect_draw.cpp"
    "src/qrect_select_test.cpp"
    "src/brick_draw.cpp"
    "src/brick_select_test.cpp"
)

set(UI_FILES
    "ui/main_window.ui"
)

find_package(QT NAMES Qt6 COMPONENTS Core Gui Widgets PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets PrintSupport REQUIRED)

set(CMAKE_AUTOUIC_SEARCH_PATHS "ui")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT6_DIR_CMAKE_PREFIX_PATH $ENV{QT6_DIR_CMAKE_PREFIX_PATH})
if ("${QT6_DIR_CMAKE_PREFIX_PATH}" STREQUAL "")
    set(QT6_DIR_CMAKE_PREFIX_PATH $ENV{QT6_DIR})
endif ()
set(CMAKE_PREFIX_PATH ${QT6_DIR_CMAKE_PREFIX_PATH})

# qt_wrap_ui(UI_HEADERS ${UI_FILES})
# CMAKE_AUTOUIC_SEARCH_PATHS("ui")
# Qt dir
get_target_property(QMAKE_EXECUTABLE Qt${QT_VERSION_MAJOR}::qmake IMPORTED_LOCATION)
get_filename_component(QT_BIN_DIR "${QMAKE_EXECUTABLE}" DIRECTORY)

# deployqt
find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${QT_BIN_DIR}")
set(PLATFORM_DEPLOYQT_EXECUTABLE ${WINDEPLOYQT_EXECUTABLE})

message(STATUS "===============")
message(STATUS "Qt envirnoment:")
message(STATUS "===============")
message(STATUS "$QT6_DIR_CMAKE_PREFIX_PATH            : $ENV{QT6_DIR_CMAKE_PREFIX_PATH}")
message(STATUS "$QT6_DIR                              : $ENV{QT6_DIR}")
message(STATUS "$QT6_DIR_WASM                         : $ENV{QT6_DIR_WASM}")
message(STATUS "QT6_DIR_CMAKE_PREFIX_PATH resolved to : ${QT6_DIR_CMAKE_PREFIX_PATH}")

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${UI_HEADERS})

target_link_libraries(
    ${PROJECT_NAME}

    # qt
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::PrintSupport
)

set (PLATFORM_DEPLOY_TARGET "$<TARGET_FILE:Arkanoid>")
set (PLATFORM_DEPLOY_ARGS   "--no-compiler-runtime")

add_custom_target(windeployqt ALL ${PLATFORM_DEPLOYQT_EXECUTABLE} --dir $<TARGET_FILE_DIR:Arkanoid>
    $<TARGET_FILE:Arkanoid>
    DEPENDS Arkanoid
    COMMENT "Preparing Qt runtime dependencies")