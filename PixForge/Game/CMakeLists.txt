cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp", "*.h")
file(GLOB_RECURSE core "../Engine/**.cpp")

project(Game VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Game WIN32 ${src} ${core})
target_link_libraries(Game PRIVATE STL)
target_link_libraries(Game PRIVATE Libraries)

target_include_directories(Game PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})