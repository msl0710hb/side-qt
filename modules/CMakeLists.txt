# 把 utils 里的源文件编成静态库，名字叫 modules
file(GLOB_RECURSE MODULES_SRCS *.cpp *.hpp)
add_library(modules STATIC ${MODULES_SRCS})
target_link_libraries(modules PUBLIC Qt6::Core)
target_include_directories(modules PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})