cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "Main.cpp" "Settings.h")

project(PixEditor VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PixEditor ${src})

add_subdirectory(PixCore)
target_link_libraries(PixEditor PRIVATE PixCore)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PixEditor)
set_property(TARGET PixEditor PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}$<CONFIG>")