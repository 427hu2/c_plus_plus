cmake_minimum_required(VERSION 3.30)

project(Greet)

set(CMAKE_CXX_STANDARD 20)

add_library(Greet
        greet.cpp
        greet.h
)

target_include_directories(Greet PUBLIC $
        {CMAKE_CURRENT_SOURCE_DIR})