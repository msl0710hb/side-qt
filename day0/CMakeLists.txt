cmake_minimum_required(VERSION 3.24)
project(QtHello)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)  # 自动处理 MOC
set(CMAKE_AUTORCC ON)  # 自动处理 RCC
set(CMAKE_AUTOUIC ON)  # 自动处理 UIC

# 查找 Qt 6 包
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
# 让 AUTOUIC 知道 .ui 文件在哪
list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

# 添加自己的类
add_subdirectory(modules)

# 添加可执行目标
qt_standard_project_setup() # qt6.4 + 提供
qt_add_executable(QtHello
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.hpp
    ui/mainwindow.ui
    resources/resources.qrc
)

target_link_libraries(QtHello PRIVATE
    Qt6::Widgets
    modules
)
