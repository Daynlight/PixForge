cmake_minimum_required(VERSION 3.10)

add_subdirectory(Forge)
add_subdirectory(Game/Game)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Forge)
set_property(TARGET Forge PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}$<CONFIG>") 