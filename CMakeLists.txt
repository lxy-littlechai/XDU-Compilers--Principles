cmake_minimum_required(VERSION 3.21)
project(Plotter_interpreter)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Scanner)


add_executable(Plotter_interpreter main.cpp ExceptionLog/ExceptionLog.cpp ExceptionLog/ExceptionLog.h)
