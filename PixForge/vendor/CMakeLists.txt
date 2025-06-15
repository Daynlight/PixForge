cmake_minimum_required(VERSION 3.10)
project(VendorLibraries LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

file(GLOB_RECURSE FILES "include/**/*.cpp")

file(GLOB_RECURSE STATIC_LIBS
    "lib/**/*.a"
)

add_library(VendorLibraries SHARED ${FILES})

target_include_directories(VendorLibraries PUBLIC
    "include/"
)

############ Windows ############
if(WIN32)
target_link_libraries(VendorLibraries PRIVATE 
    ${STATIC_LIBS}
    winmm
    imm32 
    version
    setupapi
)
endif()