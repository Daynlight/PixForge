cmake_minimum_required(VERSION 3.10)
project(Utilities LANGUAGES CXX C)

############################## FILES ##############################
file(GLOB_RECURSE FILES 
  "File/File.h" 
  "File/File.cpp" 
  "Folder/Folder.h"
  "Folder/Folder.cpp"
  "Math/Vec.h"
  "Math/Vec.hpp"
  "Vector/Vector.h"
  "Vector/Vector.hpp"
)

############################## EXECUTABLE ##############################
add_library(Utilities STATIC ${FILES})

############################## LINKING ##############################
target_include_directories(Utilities PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Utilities PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})