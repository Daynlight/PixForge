cmake_minimum_required(VERSION 3.10)
project(Platforms LANGUAGES CXX C)

file(GLOB_RECURSE FILES
  "Interface/iEditorGui.h"
  "Interface/iEditorGui.cpp"
  "Interface/iRenderer.h"
  "Interface/iDB.h"
  "Platform.h"
)

######################### Load Libraries for current setup #########################
############ [OPENGL_WIN] ############
if (BUILD_CONFIG_RENDERER STREQUAL OPENGL_WIN)
  #### [Files] ####
  set(RENDERER
    "Vendor/glad-3.3/src/glad.c"
    "Renderer/Renderer.cpp"
    )  

  find_package(glfw3 3.4 REQUIRED)

  #### [Libraries] ####
  set(RENDERER_LIBS 
    glfw
    "winmm"
    "imm32"
    "version"
    "setupapi")

  #### [Include] ####
  set(RENDERER_INCLUDE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glad-3.3/include"
  )

else()
    message(FATAL_ERROR "Current BUILD_CONFIG_RENDERER is invalid set")
endif()

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
add_library(Platforms STATIC ${RENDERER} ${SQL} ${FILES})
target_link_libraries(Platforms PUBLIC ${RENDERER_LIBS})
target_link_libraries(Platforms PUBLIC ${SQL_LIBS})
target_include_directories(Platforms PUBLIC ${RENDERER_INCLUDE})
target_include_directories(Platforms PUBLIC ${SQL_INCLUDE})

######################### Include Folders #########################
target_include_directories(Platforms PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Platforms PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})