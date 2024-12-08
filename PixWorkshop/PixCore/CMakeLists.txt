cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp" "*.h" "../Settings.h" "../vendor/ImGui/**.cpp" "../vendor/ImGui/**.h")

project(PixCore VERSION 1.0 LANGUAGES CXX)
add_library(PixCore SHARED ${src})

target_link_directories(PixCore PRIVATE "../vendor/ImGui/")

target_compile_definitions(PixCore PRIVATE DLLEXPORT)

# Find necessary packages
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(GLEW REQUIRED)

# Check if SDL2 is found and link it
if(${SDL2_FOUND})
    target_link_libraries(PixCore PRIVATE ${SDL2_LIBRARIES})
    target_compile_definitions(PixCore PRIVATE SDL2_FOUND)
endif()

# Link OpenGL and other dependencies if available
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