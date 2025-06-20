cmake_minimum_required(VERSION 3.10)
project(Engine LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE FILES "**.hpp" "**.h" "**.cpp")

add_library(Engine STATIC ${FILES})

target_link_libraries(Engine PRIVATE STL)
target_link_libraries(Engine PRIVATE Platforms)

target_include_directories(Engine PUBLIC ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})