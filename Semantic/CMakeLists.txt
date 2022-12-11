cmake_minimum_required(VERSION 3.21)
project(Semantic)

set(CMAKE_CXX_STANDARD 20)

#dependencies
#find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories(${PROJECT_SOURCE_DIR}/../headers)

add_executable(Semantic main.cpp Semantic.cpp Semantic.h Plotter.cpp Plotter.h Point.cpp Point.h)

target_link_libraries(Semantic ${PROJECT_SOURCE_DIR}/../lib/libScanner_lib.so)
target_link_libraries(Semantic ${PROJECT_SOURCE_DIR}/../lib/libParser_lib.so)
target_link_libraries(Semantic ${PROJECT_SOURCE_DIR}/../lib/libExceptionLog_lib.so)
target_link_libraries(Semantic ${OpenCV_LIBS} )