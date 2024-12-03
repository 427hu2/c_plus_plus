cmake_minimum_required(VERSION 3.30)

project(Test)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib)
add_subdirectory(pugixml)

add_executable(Test main.cpp)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(Test PRIVATE Greet nlohmann_json::nlohmann_json PugiXML)