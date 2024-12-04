cmake_minimum_required(VERSION 3.28)

project(pm)

find_package(fmt CONFIG REQUIRED)

add_executable(pm main.cpp)

target_link_libraries(pm PRIVATE fmt::fmt)