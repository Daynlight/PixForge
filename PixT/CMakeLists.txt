cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "Main.cpp" "Settings.h")

add_subdirectory(PixEditor)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PixEditor)
set_property(TARGET PixEditor PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}$<CONFIG>") 