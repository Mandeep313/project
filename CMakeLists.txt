cmake_minimum_required(VERSION 2.8)
project(BuildD)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt5.5.1/5.5/gcc_64)

set(SOURCE_FILES main.cpp EntityWriter.h EntityWriter.cpp)
add_executable(BuildD ${SOURCE_FILES})


set(DWG_LIBRARY )
FIND_LIBRARY(DXF_LIBRARY NAMES dxfrw PATHS /usr/local/lib)
INCLUDE_DIRECTORIES(/usr/local/include/libdxfrw0)

#rvt target_link_libraries(lcdxfdwg lckernel ${DXF_LIBRARY} ${DWG_LIBRARY})
target_link_libraries(BuildD ${DXF_LIBRARY})


find_package(Qt5Widgets)
target_link_libraries(BuildD Qt5::Widgets)

