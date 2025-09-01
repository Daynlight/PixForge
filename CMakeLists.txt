cmake_minimum_required(VERSION 3.10)

############################## Set Default Path ##############################
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
set(CMAKE_ROOT_DIRECTORY ${CMAKE_SOURCE_DIR}/PixForge)
set(CMAKE_OUTPUT_RENDERER ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/renderers)

######################### Set Project Language #########################
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

############################## Add libstdc++ as Static Lib ##############################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")

############################## Set Renderer and Platform ##############################
# OPENGL_WIN
set(BUILD_CONFIG_RENDERER OPENGL_WIN)
set(BUILD_CONFIG_DATA SQLITE)

############################## set toolchain to conan ##############################
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/conan/conan_toolchain.cmake" CACHE STRING "Conan toolchain file")




############################## Add All SubFolders ##############################
add_subdirectory(PixForge/Utilities)
add_subdirectory(PixForge/Platforms)
add_subdirectory(PixForge/Engine)
add_subdirectory(PixForge/Forge)



############################## Set for VS ##############################
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Forge)
set_property(TARGET Forge PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}$<CONFIG>") 
