cmake_minimum_required(VERSION 3.21)
project(Parser)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parser main.cpp)

target_link_libraries(Parser Scanner)
target_include_directories(Parser PUBLIC ../Scanner)