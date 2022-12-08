cmake_minimum_required(VERSION 3.21)
project(Plotter_interpreter)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Scanner Parser)
add_executable(Plotter_interpreter main.cpp)

#将可执行文件添加链接库
target_link_libraries(Plotter_interpreter Parser)
#将目录Parser添加到Plotter_interpreter目标路径中
target_include_directories(Plotter_interpreter PUBLIC Parser)
