cmake_minimum_required(VERSION 3.30.5)

project(gt)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gt main.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        test_add
        test_lib.cpp
)

target_link_libraries(
        test_add
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_add)