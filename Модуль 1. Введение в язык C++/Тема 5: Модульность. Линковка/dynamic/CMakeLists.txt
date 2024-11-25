cmake_minimum_required(VERSION 3.10)
project(MyDynamicLib)

# Указываем исходный файл для создания библиотеки
add_library(MyDynamicLib SHARED dynamic_lib.cpp)

# Указываем каталог, где находятся заголовочные файлы
target_include_directories(MyDynamicLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})