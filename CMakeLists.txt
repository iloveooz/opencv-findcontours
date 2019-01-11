cmake_minimum_required(VERSION 3.12)
project(opencv_findcontours)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(opencv_findcontours main.cpp)

target_link_libraries(opencv_findcontours ${OpenCV_LIBS})