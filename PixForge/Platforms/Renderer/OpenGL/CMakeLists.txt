cmake_minimum_required(VERSION 3.10)
project(OpenGLRenderer LANGUAGES CXX C)

#### [Files] ####
set(RENDERER
  "Vendor/glad-3.3/src/glad.c"
  "Renderer.cpp"
  )  

#### [Libraries] ####
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


set_target_properties(OpenGLRenderer PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_OUTPUT_RENDERER}"   # For DLLs (Windows)
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_OUTPUT_RENDERER}"   # For shared libraries (.so, .dylib)
)