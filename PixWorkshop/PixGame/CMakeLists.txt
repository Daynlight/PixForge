cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp" "*.h" "../Settings.h") 

project(PixGame VERSION 1.0 LANGUAGES CXX)
add_executable(PixGame ${src})

# Find necessary packages
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(GLEW REQUIRED)

# Check if SDL2 is found and link it
if(${SDL2_FOUND})
    target_link_libraries(PixGame PRIVATE ${SDL2_LIBRARIES})
    target_compile_definitions(PixGame PRIVATE SDL2_FOUND)
endif()

if(${OPENGL_FOUND})
    target_link_libraries(PixGame PRIVATE ${OPENGL_LIBRARIES})
    target_compile_definitions(PixGame PRIVATE OPENGL_FOUND)

    if(${GLFW3_FOUND})
        target_link_libraries(PixGame PRIVATE ${GLFW_LIBRARIES})
        target_compile_definitions(PixGame PRIVATE GLFW3_FOUND)
    endif()

    if(${GLEW_FOUND})
        target_link_libraries(PixGame PRIVATE ${GLEW_LIBRARIES})
        target_compile_definitions(PixGame PRIVATE GLEW_FOUND)
    endif()
endif()

# Link PixCore library
target_link_libraries(PixGame PRIVATE PixCore)
target_link_libraries(PixGame PRIVATE ${CMAKE_SOURCE_DIR}/PixWorkshop/vendor/Data/lib/libData.a)