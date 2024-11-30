cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp" "*.h")

project(PixCore VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(PixCore SHARED ${src})

target_compile_definitions(PixCore PRIVATE DLLEXPORT)

if(${SDL2_FOUND} OR ${OPENGL_FOUND})
  if(${SDL2_FOUND})
    target_link_libraries(PixCore PRIVATE ${SDL2_LIBRARIES})
    target_compile_definitions(PixCore PRIVATE SDL2_FOUND)
  endif()

  if(${OPENGL_FOUND})
    target_link_libraries(PixCore PRIVATE ${OPENGL_LIBRARIES})
    target_compile_definitions(PixCore PRIVATE OPENGL_FOUND)

    if(${GLFW3_FOUND})
      target_link_libraries(PixCore PRIVATE ${GLFW_LIBRARIES})
      target_compile_definitions(PixCore PRIVATE GLFW3_FOUND)
    endif()

    if(${GLEW_FOUND})
      target_link_libraries(PixCore PRIVATE ${GLEW_LIBRARIES})
      target_compile_definitions(PixCore PRIVATE GLEW_FOUND)
    endif()
  endif()
endif()