cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Forge VERSION 1.0 LANGUAGES CXX)

set(RENDERER
  "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glad-3.3/src/glad.c"
  "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/imgui-docking/imgui.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/imgui-docking/imgui_draw.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/imgui-docking/imgui_tables.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/imgui-docking/imgui_widgets.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/imgui-docking/backends/imgui_impl_glfw.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/imgui-docking/backends/imgui_impl_opengl3.cpp"
)

find_package(glfw3 3.4 REQUIRED)

set(RENDERER_LIBS
  glfw
  "winmm"
  "imm32"
  "version"
  "setupapi"
)

set(RENDERER_INCLUDE
  "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glad-3.3/include"
  "${CMAKE_CURRENT_SOURCE_DIR}/Vendor/imgui-docking"
)

file(GLOB_RECURSE src 
  "Main.cpp"
  "Forge.cpp"
  "Debug/Log.hpp"
  "Debug/Benchmark.cpp"
  "Gui/Gui.cpp"
  "Renderer/Renderer.cpp"
)

file(GLOB_RECURSE header 
  "Forge.h"
  "Debug/Log.h"
  "Debug/Benchmark.h"
)

add_executable(Forge WIN32 ${src} ${header} ${RENDERER})

target_link_libraries(Forge PUBLIC ${RENDERER_LIBS})
target_link_libraries(Forge PRIVATE Engine)

target_include_directories(Forge PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Forge PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Forge PRIVATE ${RENDERER_INCLUDE})