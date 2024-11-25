cmake_minimum_required(VERSION 3.30.0)

project(homework)

add_subdirectory(./static MyStaticLib)

add_executable(homework main.cpp)

target_link_libraries(homework MyStaticLib)