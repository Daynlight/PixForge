cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "Main.cpp" "Settings.h")

project(PixT VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PixT ${src})

find_package(SDL2 REQUIRED)
add_subdirectory(PixEditor)
target_link_libraries(PixT PRIVATE PixEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PixT)
set_property(TARGET PixT PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}$<CONFIG>") 