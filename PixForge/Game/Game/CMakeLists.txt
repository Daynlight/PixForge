cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp", "*.h")
file(GLOB_RECURSE core "../../Core/**.cpp")

project(Game VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable(Game WIN32 ${src} ${core})

find_package(SDL2 REQUIRED)
target_link_libraries(Game PRIVATE ${SDL2_LIBRARIES})
target_link_libraries(Game PRIVATE ${libraries})

target_include_directories(Game PRIVATE ${SDL2_INCLUDE_DIRS})