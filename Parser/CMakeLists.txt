cmake_minimum_required(VERSION 3.21)
project(Parser)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parser main.cpp TreeNode.cpp TreeNode.h Parser.cpp Parser.h)
include_directories(${PROJECT_SOURCE_DIR}/../headers)


target_link_libraries(Parser ${PROJECT_SOURCE_DIR}/../lib/libScanner_lib.so)
target_link_libraries(Parser ${PROJECT_SOURCE_DIR}/../lib/libExceptionLog_lib.so)