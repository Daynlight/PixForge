cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp" "*.h")  
file(GLOB_RECURSE libs "../vendor/imgui/*.cpp")
file(GLOB_RECURSE core "../Core/*.cpp")
file(GLOB_RECURSE libraries "../vendor/data/lib/*.a")

project(PixEditor VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PixEditor WIN32 ${src} ${libs} ${core})

find_package(SDL2 REQUIRED)
target_link_libraries(PixEditor PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(PixEditor PRIVATE ${libraries})

target_include_directories(PixEditor PRIVATE ${SDL2_INCLUDE_DIRS})

add_custom_command(TARGET PixEditor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Assets/
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/PixT/Assets/ ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Assets/

    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/vendor/
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/PixT/vendor/ ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/vendor/

    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Game/
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/PixT/Game/ ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Game/

    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Core/
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/PixT/Core/ ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Core/

    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/buildScripts/
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/PixT/buildScripts/ ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/buildScripts/
    COMMENT "Copying folders"
)