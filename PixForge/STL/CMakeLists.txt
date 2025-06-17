cmake_minimum_required(VERSION 3.10)
project(STLLibraries LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE FILES "**.hpp" "**.cpp")

add_library(STLLibraries STATIC ${FILES})
target_include_directories(STLLibraries PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})