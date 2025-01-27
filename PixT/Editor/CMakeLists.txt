cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp" "*.h")  
file(GLOB_RECURSE core "../Core/*.cpp")
file(GLOB_RECURSE game "../Game/*.cpp")
list(FILTER game EXCLUDE REGEX ".*Main\\.cpp$")
file(GLOB_RECURSE libs "../vendor/imgui/*.cpp")
file(GLOB_RECURSE libraries "../vendor/data/lib/*.a")

project(PixEditor VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PixEditor WIN32 ${src} ${libs} ${core} ${game})

find_package(SDL2 REQUIRED)
target_link_libraries(PixEditor PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(PixEditor PRIVATE ${libraries})
target_include_directories(PixEditor PRIVATE ${SDL2_INCLUDE_DIRS})