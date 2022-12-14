cmake_minimum_required(VERSION 3.21)
project(Parser)

set(CMAKE_CXX_STANDARD 20)
include_directories(${PROJECT_SOURCE_DIR}/../headers)
add_executable(Parser main.cpp TreeNode.h Parser.cpp Parser.h)

#add_custom_command(TARGET Parser PRE_BUILD COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/Parser.h ${CMAKE_SOURCE_DIR}/headers)
#add_custom_command(TARGET Parser PRE_BUILD COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/TreeNode.h ${CMAKE_SOURCE_DIR}/headers)

add_library(Parser_lib SHARED ${CMAKE_CURRENT_SOURCE_DIR}/Parser.cpp)
install(TARGETS Parser_lib LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(Parser ${CMAKE_SOURCE_DIR}/lib/libScanner_lib.so)
target_link_libraries(Parser ${CMAKE_SOURCE_DIR}/lib/libExceptionLog_lib.so)