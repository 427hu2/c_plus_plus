cmake_minimum_required(VERSION 3.10)
project(MyStaticLib)

# Указываем исходный файл для создания библиотеки
add_library(MyStaticLib STATIC static_lib.cpp)

# Указываем каталог, где находятся заголовочные файлы
target_include_directories(MyStaticLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})