cmake_minimum_required(VERSION 3.10)
project(Platforms LANGUAGES CXX C)

######################### Load Libraries for current setup #########################
if (BUILD_CONFIG STREQUAL OPENGL_WIN) #### [OPENGL_WIN] ####
  file(GLOB_RECURSE GLAD
    "Vendor/glad-3.3/src/glad.c"
  )  

  add_subdirectory(Vendor/glfw-3.4)

  file(GLOB_RECURSE IMGUI
        "imgui-1.91.9b/imgui.cpp"
        "imgui-1.91.9b/imgui_draw.cpp"
        "imgui-1.91.9b/backend/imgui_impl_glfw3.cpp"
        "imgui-1.91.9b/backend/imgui_impl_sdlrenderer2.cpp"
        "imgui-1.91.9b/imgui_tables.cpp"
        "imgui-1.91.9b/imgui_widgets.cpp"
    )

    add_library(Platforms STATIC ${GLAD})
    target_link_libraries(Platforms PRIVATE ${STATIC_LIBS})
    
    target_link_libraries(Platforms PRIVATE
      winmm
      imm32 
      version
      setupapi
    )
else()
    message(FATAL_ERROR "Current RENDERER is invalid set")
endif()


 ######################### Include Folders #########################
target_include_directories(Platforms PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glad-3.3/include)
target_include_directories(Platforms PRIVATE ${CMAKE_ROOT_DIRECTORY})
target_include_directories(Platforms PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})