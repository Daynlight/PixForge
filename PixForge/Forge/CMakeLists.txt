cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Forge VERSION 1.0 LANGUAGES CXX)

set(RENDERER
  "${CMAKE_SOURCE_DIR}/vendor/glad/src/glad.c"
  "${CMAKE_SOURCE_DIR}/vendor/imgui/imgui.cpp"
  "${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_draw.cpp"
  "${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_tables.cpp"
  "${CMAKE_SOURCE_DIR}/vendor/imgui/imgui_widgets.cpp"
  "${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_glfw.cpp"
  "${CMAKE_SOURCE_DIR}/vendor/imgui/backends/imgui_impl_opengl3.cpp"
)

set(RENDERER_LIBS
  glfw
)
if(WIN32)
  list(APPEND RENDERER_LIBS
    "winmm"
    "imm32"
    "version"
    "setupapi"
  )
elseif(UNIX)
  list(APPEND RENDERER_LIBS
    X11
    Xrandr
    Xcursor
    Xi
  )
endif()

set(RENDERER_INCLUDE
  "${CMAKE_SOURCE_DIR}/vendor/glad/include"
  "${CMAKE_SOURCE_DIR}/vendor/imgui"
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