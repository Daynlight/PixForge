cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "Main.cpp" "Settings.h")

project(PixWorkbench VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PixWorkbench ${src})

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(GLEW REQUIRED)

if(${SDL2_FOUND} OR ${OPENGL_FOUND})
  if(${SDL2_FOUND})
    target_compile_definitions(PixWorkbench PRIVATE SDL2_FOUND)
    set(SDL2_FOUND TRUE CACHE BOOL "Enable some feature in PixCore")
  endif()

  if(${OPENGL_FOUND})
    target_compile_definitions(PixWorkbench PRIVATE OPENGL_FOUND)
    set(OPENGL_FOUND TRUE CACHE BOOL "Enable some feature in PixCore")

    if(${GLFW3_FOUND})
      target_compile_definitions(PixWorkbench PRIVATE GLFW3_FOUND)
      set(GLFW3_FOUND TRUE CACHE BOOL "Enable some feature in PixCore")
    endif()

    if(${GLEW_FOUND})
      target_compile_definitions(PixWorkbench PRIVATE GLEW_FOUND)
      set(GLEW_FOUND TRUE CACHE BOOL "Enable some feature in PixCore")
    endif()
  endif()
else()
  message(FATAL_ERROR "No SDL2 or OpenGL")
endif()

add_subdirectory(PixCore)
target_link_libraries(PixWorkbench PRIVATE PixCore)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT PixWorkbench)
set_property(TARGET PixWorkbench PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}$<CONFIG>")