cmake_minimum_required(VERSION 3.16)

project(QtTodoUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        todoui.cpp
        todoui.h
        todoui.ui
        todoitem.cpp
        todoitem.h
        todoitem.ui
)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtTodoUI
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        button.cpp button.h button.ui
        head.h head.cpp head.ui
        finishenabletab.h finishenabletab.cpp finishenabletab.ui
        inputwidget.h inputwidget.cpp inputwidget.ui
        calendardialog.h calendardialog.cpp
        mainwindow.h mainwindow.cpp mainwindow.ui
        centeralcontent.h centeralcontent.cpp centeralcontent.ui
        icons.qrc
        todoitem.h todoitem.cpp todoitem.ui
        todolistwidget.h todolistwidget.cpp todolistwidget.ui
        DataManage.h DataManage.cpp
        Todo.h Todo.cpp
        Todo.cpp Todo.h
        TodoRepo.h TodpRepoFile.cpp
        UserTodo.h UserTodo.cpp
        UserTodoConverter.h UserTodoConverter.cpp
    )
    # qt_add_executable(QtTodoUI MANUAL_FINALIZATION icons.qrc src ui include main.cpp)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QtTodoUI APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QtTodoUI SHARED
            ${PROJECT_SOURCES}
            todo
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QtTodoUI
            ${PROJECT_SOURCES}
            todo
        )
    endif()
endif()

target_link_libraries(QtTodoUI PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.QtTodoUI)
endif()
set_target_properties(QtTodoUI PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QtTodoUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QtTodoUI)
endif()
