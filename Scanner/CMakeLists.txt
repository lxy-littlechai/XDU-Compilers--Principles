cmake_minimum_required(VERSION 3.21)
project(Scanner)

set(CMAKE_CXX_STANDARD 20)

add_executable(Scanner main.cpp Token.cpp Token.h Scanner.cpp Scanner.h Func.h)

include_directories(${PROJECT_SOURCE_DIR}/../headers)
target_link_libraries(Scanner ${PROJECT_SOURCE_DIR}/../lib/libExceptionLog_lib.so)


