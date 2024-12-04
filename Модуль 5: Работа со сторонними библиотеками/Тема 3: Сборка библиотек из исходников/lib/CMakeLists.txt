cmake_minimum_required(VERSION 3.30.1)

project(Add)

add_library(Add STATIC
    add.cpp
    add.h
)

target_include_directories(Add PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})