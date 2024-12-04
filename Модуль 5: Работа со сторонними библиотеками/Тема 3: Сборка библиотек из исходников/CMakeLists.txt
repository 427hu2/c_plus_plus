cmake_minimum_required(VERSION 3.30.5)

project(libs)

add_subdirectory(lib)

include(ExternalProject)

# Настройка проекта для загрузки и сборки zlib
ExternalProject_Add(
        zlib_external
        URL https://zlib.net/zlib-1.2.13.tar.gz  # Укажите версию zlib, которую хотите использовать
        URL_HASH SHA256=2d114d200b9f4c3b8dbd467a0c7c4ec63d0c4e2c09d8aa1c1485e4ed2b2a0b3c
        PREFIX ${CMAKE_BINARY_DIR}/zlib
        CONFIGURE_COMMAND ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR> -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} <SOURCE_DIR>
        BUILD_COMMAND ${CMAKE_COMMAND} --build <BINARY_DIR>
        INSTALL_COMMAND ${CMAKE_COMMAND} --install <BINARY_DIR>
        BUILD_BYPRODUCTS <INSTALL_DIR>/lib/libz.a
)

# Подключение скомпилированной библиотеки к вашему проекту
add_library(zlib STATIC IMPORTED)
set_target_properties(zlib PROPERTIES
        IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/zlib/lib/libz.a
        INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_BINARY_DIR}/zlib/include
)

# Укажите зависимость для вашей цели
add_dependencies(zlib zlib_external)

add_executable(libs main.cpp)

target_link_libraries(libs Add zlib)