cmake_minimum_required(VERSION 3.10)
project(STL LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE FILES 
  "File/File.h" 
  "File/File.cpp" 
  "Folder/Folder.h"
  "Folder/Folder.cpp"
  "Math/Vec.h"
  "Vector/Vector.h"
  "Vector/Vector.cpp"
)

add_library(STL STATIC ${FILES})

target_include_directories(STL PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(STL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})