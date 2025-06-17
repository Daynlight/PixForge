cmake_minimum_required(VERSION 3.10)

############################## Set Default Path ##############################
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output)
set(CMAKE_ROOT_DIRECTORY ${CMAKE_SOURCE_DIR}/PixForge)

######################### Set Project Language #########################
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

############################## Add libstdc++ as Static Lib ##############################
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")

############################## Set Renderer and Platform ##############################
# SDL2, OPENGL
set(RENDERER SDL2)
# WIN, UNIX
set(PLATFORM WIN)

############################## Add All SubFolders ##############################
add_subdirectory(PixForge/vendor)
add_subdirectory(PixForge/STL)
add_subdirectory(PixForge/Engine)
add_subdirectory(PixForge/Forge)
add_subdirectory(PixForge/Game)

############################## Set for VS ##############################
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Forge)
set_property(TARGET Forge PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}$<CONFIG>") 
