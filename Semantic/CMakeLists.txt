cmake_minimum_required(VERSION 3.21)
project(Semantic)

set(CMAKE_CXX_STANDARD 20)

#dependencies
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories(${PROJECT_SOURCE_DIR}/../headers)

add_executable(Semantic main.cpp Semantic.cpp Semantic.h Plotter.cpp Plotter.h Point.cpp Point.h)
#add_custom_command(TARGET Semantic PRE_BUILD COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/Semantic.h ${CMAKE_SOURCE_DIR}/headers)
#add_custom_command(TARGET Semantic PRE_BUILD COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/Plotter.h ${CMAKE_SOURCE_DIR}/headers)
#add_custom_command(TARGET Semantic PRE_BUILD COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/Point.h ${CMAKE_SOURCE_DIR}/headers)

add_library(Semantic_lib SHARED ${CMAKE_CURRENT_SOURCE_DIR}/Semantic.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Plotter.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Point.cpp)
install(TARGETS Semantic_lib LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib)

target_link_libraries(Semantic ${CMAKE_SOURCE_DIR}/lib/libScanner_lib.so)
target_link_libraries(Semantic ${CMAKE_SOURCE_DIR}/lib/libParser_lib.so)
target_link_libraries(Semantic ${CMAKE_SOURCE_DIR}/lib/libExceptionLog_lib.so)
target_link_libraries(Semantic ${OpenCV_LIBS} )