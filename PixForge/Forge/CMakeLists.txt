cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "**.cpp" "**.h")

project(Forge VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Forge WIN32 ${src})

target_link_libraries(Forge PRIVATE STL)
target_link_libraries(Forge PRIVATE Libraries)
target_link_libraries(Forge PRIVATE Engine)

target_include_directories(Forge PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Forge PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})