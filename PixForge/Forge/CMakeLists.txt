cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE src 
  "Main.cpp"
  "Forge.cpp"
  "Log.cpp"
  "Debug/Benchmark.cpp"
)

file(GLOB_RECURSE header 
  "Forge.h"
  "Log.h"
  "Debug/Benchmark.h"
)

project(Forge VERSION 1.0 LANGUAGES CXX)

add_executable(Forge WIN32 ${src} ${header})

target_link_libraries(Forge PRIVATE Engine)

target_include_directories(Forge PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Forge PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})