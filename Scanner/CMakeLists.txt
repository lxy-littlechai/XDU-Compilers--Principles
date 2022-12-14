cmake_minimum_required(VERSION 3.21)
project(Scanner)

set(CMAKE_CXX_STANDARD 20)
add_executable(Scanner main.cpp Token.cpp Token.h Scanner.cpp Scanner.h Func.h)

#add_custom_command(TARGET Scanner PRE_BUILD COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/Scanner.h ${CMAKE_SOURCE_DIR}/headers)
#add_custom_command(TARGET Scanner PRE_BUILD COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/Func.h ${CMAKE_SOURCE_DIR}/headers)
#add_custom_command(TARGET Scanner PRE_BUILD COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/Token.h ${CMAKE_SOURCE_DIR}/headers)

add_library(Scanner_lib SHARED ${CMAKE_CURRENT_SOURCE_DIR}/Scanner.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Token.cpp)
install(TARGETS Scanner_lib LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib)

include_directories(${CMAKE_SOURCE_DIR}/headers)
target_link_libraries(Scanner ${CMAKE_SOURCE_DIR}/lib/libExceptionLog_lib.so)


