cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp" "*.h")

project(PixCore VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(PixCore SHARED ${src})

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(GLEW REQUIRED)

if(${SDL2_FOUND} OR ${OPENGL_FOUND})
  if(${SDL2_FOUND})
    target_link_libraries(PixCore PRIVATE ${SDL2_LIBRARIES})
  endif()

  if(${OPENGL_FOUND})
    target_link_libraries(PixCore PRIVATE ${OPENGL_LIBRARIES})

    if(${GLFW3_FOUND})
      target_link_libraries(PixCore PRIVATE ${GLFW_LIBRARIES})
    endif()

    if(${GLEW_FOUND})
      target_link_libraries(PixCore PRIVATE ${GLEW_LIBRARIES})
    endif()
  endif()

else()
  message(FATAL_ERROR "At least one of SDL2 or OpenGL must be found")
endif()