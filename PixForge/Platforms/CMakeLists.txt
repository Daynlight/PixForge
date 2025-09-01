cmake_minimum_required(VERSION 3.10)
project(Platforms LANGUAGES CXX C)

file(GLOB_RECURSE FILES
  "Interface/iRenderer.h"
  "Interface/iDB.h"
  "Platform.h"
  "Platform.cpp"
)

######################### Load Libraries for current setup #########################
add_subdirectory(Renderer)

######################### Data #########################
######################### SQLITE #########################
if (BUILD_CONFIG_DATA STREQUAL SQLITE)
  find_package(SQLite3 REQUIRED)

  #### [Files] ####
  set(SQL "SQL/SQL.h")

  #### [Libraries] ####
  set(SQL_LIBS "${SQLite3_LIBRARIES}")

  #### [Include] ####
  set(SQL_INCLUDE
    "${SQLite3_INCLUDE}")
else()
    message(FATAL_ERROR "Current BUILD_CONFIG_DATA is invalid set")
endif()

######################### Finishing #########################
add_library(Platforms STATIC ${SQL} ${FILES})
target_link_libraries(Platforms PUBLIC ${SQL_LIBS})
target_include_directories(Platforms PUBLIC ${SQL_INCLUDE})

######################### Include Folders #########################
target_include_directories(Platforms PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Platforms PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})