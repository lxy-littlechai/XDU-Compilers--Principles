cmake_minimum_required(VERSION 3.21)
project(Plotter_interpreter)

set(CMAKE_CXX_STANDARD 20)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

##headers
install(FILES ${PROJECT_SOURCE_DIR}/ExceptionLog/ExceptionLog.h DESTINATION ${PROJECT_SOURCE_DIR}/headers)
add_library(ExceptionLog_lib SHARED ${PROJECT_SOURCE_DIR}/ExceptionLog/ExceptionLog.cpp)
install(TARGETS ExceptionLog_lib LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(Scanner)
add_subdirectory(Parser)
add_subdirectory(Semantic)

add_executable(Plotter_interpreter main.cpp)
target_link_libraries(Plotter_interpreter ${OpenCV_LIBS} )

include_directories(${PROJECT_SOURCE_DIR}/headers)

target_link_libraries(Plotter_interpreter ${PROJECT_SOURCE_DIR}/lib/libExceptionLog_lib.so ${PROJECT_SOURCE_DIR}/lib/libScanner_lib.so
      ${PROJECT_SOURCE_DIR}/lib/libParser_lib.so ${PROJECT_SOURCE_DIR}/lib/libSemantic_lib.so)

add_library(allLib SHARED ${PROJECT_SOURCE_DIR}/Scanner/Scanner.cpp ${PROJECT_SOURCE_DIR}/Scanner/Token.cpp
        ${PROJECT_SOURCE_DIR}/Parser/Parser.cpp
        ${PROJECT_SOURCE_DIR}/Semantic/Semantic.cpp ${PROJECT_SOURCE_DIR}/Semantic/Plotter.cpp ${PROJECT_SOURCE_DIR}/Semantic/Point.cpp
        ${PROJECT_SOURCE_DIR}/ExceptionLog/ExceptionLog.cpp)
install(TARGETS allLib LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(Plotter_interpreter ${PROJECT_SOURCE_DIR}/lib/liballLib.so)
target_link_libraries(Plotter_interpreter ${PROJECT_SOURCE_DIR}/lib/libopencv_highgui.so)