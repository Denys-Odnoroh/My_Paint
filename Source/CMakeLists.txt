cmake_minimum_required(VERSION 3.5)

project(MyPaint VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets)

set(PROJECT_SOURCES
        main.cpp
        MainWindow.h
        WorkSurfaceWidget.h
        PaintScene.h
        ToolbarWidget.h
        Settings.h
        BaseCreator.h
        CurveCreator.h
        CircleCreator.h
        RectangleCreator.h
        Entityes.h
        ObjectChangeHistory.h
        ObjectChangeHistory.cpp
        Entityes.cpp
        MainWindow.cpp
        WorkSurfaceWidget.cpp
        PaintScene.cpp
        ToolbarWidget.cpp
        Settings.cpp
        CurveCreator.cpp
        CircleCreator.cpp
        RectangleCreator.cpp
        BaseCreator.cpp
        WorkSurfaceWidget.ui
        MainWindow.ui
        ToolbarWidget.ui
        Resourse.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MyPaint
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MyPaint APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MyPaint SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MyPaint
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MyPaint PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MyPaint PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::OpenGL
    Qt6::OpenGLWidgets
    Qt6::Widgets
)

set_target_properties(MyPaint PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS MyPaint
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MyPaint)
endif()
