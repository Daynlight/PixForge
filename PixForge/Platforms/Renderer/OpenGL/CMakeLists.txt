cmake_minimum_required(VERSION 3.10)
project(OpenGLRenderer LANGUAGES CXX C)

#### [Files] ####
set(RENDERER
  "Vendor/glad-3.3/src/glad.c"
  "Renderer.cpp"
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
  "Renderer.h"
)

add_library(OpenGLRenderer SHARED ${RENDERER})

target_link_libraries(OpenGLRenderer PUBLIC ${RENDERER_LIBS})
target_link_libraries(OpenGLRenderer PUBLIC Utilities)
target_include_directories(OpenGLRenderer PUBLIC ${RENDERER_INCLUDE})
target_include_directories(OpenGLRenderer PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(OpenGLRenderer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})