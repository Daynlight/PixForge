cmake_minimum_required(VERSION 3.10)
project(Platforms LANGUAGES CXX C)

file(GLOB_RECURSE FILES
  "Interface/iEditorGui.h"
  "Interface/iEditorGui.cpp"
  "Interface/iRenderer.h"
  "Platform.h"
)

######################### Load Libraries for current setup #########################
############ [OPENGL_WIN] ############
if (BUILD_CONFIG STREQUAL OPENGL_WIN)
  #### [Libraries] ####
  file(GLOB_RECURSE GLAD
    "Vendor/glad-3.3/src/glad.c"
  )  
  add_subdirectory(Vendor/glfw-3.4)
  file(GLOB_RECURSE IMGUI
    "Vendor/imgui-docking/imgui.cpp"
    "Vendor/imgui-docking/imgui_draw.cpp"
    "Vendor/imgui-docking/imgui_tables.cpp"
    "Vendor/imgui-docking/imgui_widgets.cpp"
    "Vendor/imgui-docking/backends/imgui_impl_glfw.cpp"
    "Vendor/imgui-docking/backends/imgui_impl_opengl3.cpp"
  )

  #### [Files] ####
  file(GLOB_RECURSE SPECIFIC_FILES
    "OpenGL/Win/Renderer/Renderer.cpp"
    "OpenGL/Win/EditorGui/EditorGui.cpp"
  )

  add_library(Platforms STATIC ${GLAD} ${IMGUI} ${FILES} ${SPECIFIC_FILES})

  #### [Link Libraries] ####
  target_link_libraries(Platforms PUBLIC
    STL
    glfw
    winmm
    imm32 
    version
    setupapi
  )
  #### [Include] ####
  target_include_directories(Platforms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glad-3.3/include)
  target_include_directories(Platforms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/imgui-docking)
  target_include_directories(Platforms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glfw-3.4/include)
else()
    message(FATAL_ERROR "Current BUILD_CONFIG is invalid set")
endif()

######################### Include Folders #########################
target_include_directories(Platforms PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Platforms PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})