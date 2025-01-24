cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp", "*.h")
file(GLOB_RECURSE core "../PixCore/*.cpp")

project(PixGame VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(PixGame ${src} ${core})

find_package(SDL2 REQUIRED)
target_link_libraries(PixGame PRIVATE ${SDL2_LIBRARIES})
target_include_directories(PixGame PRIVATE ${SDL2_INCLUDE_DIRS})

target_include_directories(PixGame PUBLIC "../PixCore")
target_include_directories(PixGame PUBLIC "../Assets")