cmake_minimum_required(VERSION 3.24)
project(day3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)  # 自动处理 MOC
set(CMAKE_AUTORCC ON)  # 自动处理 RCC
set(CMAKE_AUTOUIC ON)  # 自动处理 UIC

# 查找 Qt 6 包
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
# 让 AUTOUIC 知道 .ui 文件在哪
list(APPEND CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui)

# 手动列出所有源文件 .cpp
set(MODULES_SOURCES
    modules/utils/StringUtils.cpp
    modules/counter/counter.cpp
    # 后续新增 .cpp 继续往下写
)

# 创建静态库
add_library(modules STATIC ${MODULES_SOURCES})

# 链接 Qt6
target_link_libraries(modules PUBLIC Qt6::Core)

# 暴露头文件目录
target_include_directories(modules
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/modules>
        $<INSTALL_INTERFACE:include>
)

# 把头文件挂给 IDE
target_sources(modules PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/modules
    FILES
        modules/utils/StringUtils.h
        modules/counter/counter.h
        # 后续新增 .h 继续往下写
)

# 添加可执行目标
qt_standard_project_setup() # qt6.4 + 提供
qt_add_executable(day3
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    ui/mainwindow.ui
    resources/resources.qrc
)

target_link_libraries(day3 PRIVATE
    Qt6::Widgets
    modules
)
