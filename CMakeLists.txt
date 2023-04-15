cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
set (CMAKE_CXX_FLAGS "-O3 -g3 -std=c++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "")

project(map_format)

include_directories(${PROJECT_SOURCE_DIR})
link_directories(${PROJECT_SOURCE_DIR})

find_package (OpenCV REQUIRED)

add_executable (main main.cpp Map.cpp)
add_executable (binary binary.cpp)
target_link_libraries(main ${OpenCV_LIBRARIES})
