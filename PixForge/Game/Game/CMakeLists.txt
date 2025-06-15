cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp", "*.h")
file(GLOB_RECURSE core "../../Core/**.cpp")

project(Game VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Game WIN32 ${src} ${core})

file(GLOB_RECURSE libraries "../../vendor/lib/SDL2/**.a")
target_link_libraries(Game PRIVATE 
    ${libraries}
    winmm
    imm32 
    version
    setupapi
)

target_include_directories(Game PRIVATE ".")
target_include_directories(Game PRIVATE "../../Core/")
target_include_directories(Game PRIVATE "../../vendor/include")