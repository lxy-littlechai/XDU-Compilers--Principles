cmake_minimum_required(VERSION 3.21)
project(Plotter_interpreter)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Scanner)
add_subdirectory(Parser)
add_executable(Plotter_interpreter main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/headers)

# dynamic reference Scanner
add_library(Scanner SHARED ${PROJECT_SOURCE_DIR}/Scanner/Scanner.cpp ${PROJECT_SOURCE_DIR}/Scanner/Token.cpp)
install(TARGETS Scanner LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib)
install(FILES ${PROJECT_SOURCE_DIR}/Scanner/Scanner.h DESTINATION ${PROJECT_SOURCE_DIR}/headers)
install(FILES ${PROJECT_SOURCE_DIR}/Scanner/Token.h DESTINATION ${PROJECT_SOURCE_DIR}/headers)
install(FILES ${PROJECT_SOURCE_DIR}/Scanner/Func.h DESTINATION ${PROJECT_SOURCE_DIR}/headers)

# dynamic reference ExceptionLog
add_library(ExceptionLog SHARED ${PROJECT_SOURCE_DIR}/ExceptionLog/ExceptionLog.cpp)
install(TARGETS ExceptionLog LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib)
install(FILES ${PROJECT_SOURCE_DIR}/ExceptionLog/ExceptionLog.h DESTINATION ${PROJECT_SOURCE_DIR}/headers)
