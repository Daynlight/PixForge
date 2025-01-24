cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp" "*.h")

project(PixCore VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(PixCore SHARED ${src})

target_compile_definitions(PixCore PRIVATE DLLEXPORT)

target_link_libraries(PixCore PRIVATE ${SDL2_LIBRARIES})
target_compile_definitions(PixCore PRIVATE SDL2_FOUND)