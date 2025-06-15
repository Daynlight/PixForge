cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "**.cpp" "**.h")  
file(GLOB_RECURSE core "../Core/**.cpp")

project(Forge VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Forge WIN32 ${src} ${core})
target_link_libraries(Forge PRIVATE VendorLibraries)

target_include_directories(Forge PRIVATE ".")
target_include_directories(Forge PRIVATE "../Core/")
target_include_directories(Forge PRIVATE "../vendor/include")