cmake_minimum_required(VERSION 3.10)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Paths
set(VENDOR_PATH ${CMAKE_CURRENT_SOURCE_DIR}/PixForge/vendor)
set(FORGE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/PixForge/Forge)
set(CORE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/PixForge/Core)

# Forge
project(Forge)
file(GLOB_RECURSE FORGE_SRC
  ${FORGE_PATH}/main.cpp
  ${FORGE_PATH}/Forge.cpp
)
file(GLOB_RECURSE FORGE_INCLUDE
  ${FORGE_PATH}/Forge.h
)
add_executable(Forge ${FORGE_SRC} ${FORGE_INCLUDE})

# Core
project(Core)
file(GLOB_RECURSE CORE_SRC
  ${CORE_PATH}/Renderer/Renderer.cpp
  ${CORE_PATH}/Renderer/SDL/SDLRenderer.cpp
)
file(GLOB_RECURSE CORE_INCLUDE
  ${CORE_PATH}/Renderer/Renderer.h
  ${CORE_PATH}/Renderer/SDL/SDLRenderer.h
)
file(GLOB_RECURSE CORE_LIBRARIES
  ${VENDOR_PATH}/SDL2/lib/SDL2.a
  ${VENDOR_PATH}/SDL2/lib/SDL2main.a
)
add_library(Core STATIC ${CORE_SRC} ${CORE_INCLUDE})
target_link_libraries(Core ${CORE_LIBRARIES})
target_include_directories(Core PRIVATE ${VENDOR_PATH}/SDL2/include)

# Link
target_include_directories(Core PRIVATE ${CORE_PATH})