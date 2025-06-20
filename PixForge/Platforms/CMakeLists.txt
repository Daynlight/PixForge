cmake_minimum_required(VERSION 3.10)
project(Platforms LANGUAGES CXX C)

file(GLOB_RECURSE FILES
  "Interface/iEditorGui.h"
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
    "imgui-1.91.9b/imgui.cpp"
    "imgui-1.91.9b/imgui_draw.cpp"
    "imgui-1.91.9b/imgui_tables.cpp"
    "imgui-1.91.9b/imgui_widgets.cpp"
    "imgui-1.91.9b/backend/imgui_impl_glfw.cpp"
    "imgui-1.91.9b/backend/imgui_impl_opengl3.cpp"
    "imgui-1.91.9b/backend/imgui_impl_opengl3_loader.cpp"
  )

  #### [Files] ####
  file(GLOB_RECURSE SPECIFIC_FILES
    "EditorGui/ImGui.cpp"
    "OpenGL/Win/Renderer/Renderer.cpp"
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
  target_include_directories(Platforms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/imgui-1.91.9b)
  target_include_directories(Platforms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glfw-3.4/include)
else()
    message(FATAL_ERROR "Current BUILD_CONFIG is invalid set")
endif()

######################### Include Folders #########################
target_include_directories(Platforms PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Platforms PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})