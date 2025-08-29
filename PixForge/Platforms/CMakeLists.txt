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
  #### [Add Folders] ####
  add_subdirectory(Vendor/glfw-3.4)

  #### [Files] ####
  set(RENDERER
    "Vendor/glad-3.3/src/glad.c"
    "Vendor/imgui-docking/imgui.cpp"
    "Vendor/imgui-docking/imgui_draw.cpp"
    "Vendor/imgui-docking/imgui_tables.cpp"
    "Vendor/imgui-docking/imgui_widgets.cpp"
    "Vendor/imgui-docking/backends/imgui_impl_glfw.cpp"
    "Vendor/imgui-docking/backends/imgui_impl_opengl3.cpp"
    "OpenGL/Win/Renderer/Renderer.cpp"
    "OpenGL/Win/EditorGui/EditorGui.cpp")  

  #### [Libraries] ####
  set(RENDERER_LIBS 
    "STL"
    "glfw"
    "winmm"
    "imm32"
    "version"
    "setupapi")

  #### [Include] ####
  set(RENDERER_INCLUDE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glad-3.3/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/imgui-docking"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glfw-3.4/include")

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