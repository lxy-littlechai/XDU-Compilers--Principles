cmake_minimum_required(VERSION 3.21)
project(Plotter_interpreter)

set(CMAKE_CXX_STANDARD 20)

add_executable(Scanner main.cpp Token.cpp Token.h Func.cpp Func.h Scanner.cpp Scanner.h)
