cmake_minimum_required(VERSION 3.23)
project(Tree-Visualizer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Tree-Visualizer main.cpp mainwindow.cpp Trees/Splay.h Trees/Treap.cpp Trees/AVL.cpp Trees/RBT.cpp graphicsview.cpp Trees/Splay.cpp)
target_link_libraries(Tree-Visualizer
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )