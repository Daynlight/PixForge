cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE FILES 
"Engine.h"
"Engine.cpp" 
"Shader.h"
"Texture.h"
)

project(Engine LANGUAGES CXX C)

add_library(Engine STATIC ${FILES})

target_link_libraries(Engine PRIVATE Utilities)
target_link_libraries(Engine PUBLIC Platforms)
target_include_directories(Engine PUBLIC ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
