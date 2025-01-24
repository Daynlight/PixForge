cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE src "*.cpp", "*.h")

project(PixApp VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(PixApp SHARED ${src})