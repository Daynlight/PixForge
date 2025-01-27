cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp", "*.h")
file(GLOB_RECURSE core "../Core/*.cpp")
file(GLOB_RECURSE libraries "../vendor/data/lib/*.a")

project(PixGame VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PixGame WIN32 ${src} ${core})

find_package(SDL2 REQUIRED)
target_link_libraries(PixGame PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(PixGame PRIVATE ${libraries})

target_include_directories(PixGame PRIVATE ${SDL2_INCLUDE_DIRS})
target_include_directories(PixGame PUBLIC "../vendor/data")
target_include_directories(PixGame PUBLIC "../Core")
target_include_directories(PixGame PUBLIC "../Assets")

target_compile_definitions(PixGame PUBLIC BUILD)