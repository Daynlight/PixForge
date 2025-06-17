cmake_minimum_required(VERSION 3.10)

project(Libraries LANGUAGES CXX C)
set(FILES "")
set(STATIC_LIBS "")

######################### Load Libraries for current setup #########################
if (RENDERER STREQUAL SDL2) #### [SDL2] ####
    file(GLOB_RECURSE IMGUI 
        "include/imgui/imgui.cpp"
        "include/imgui/imgui_draw.cpp"
        "include/imgui/imgui_impl_sdl2.cpp"
        "include/imgui/imgui_impl_sdlrenderer2.cpp"
        "include/imgui/imgui_tables.cpp"
        "include/imgui/imgui_widgets.cpp"
    )
    file(GLOB_RECURSE STATIC_LIBS
        "lib/SDL2/libSDL2.a"
        "lib/SDL2/libSDL2main.a"
        "lib/SDL2_image/libSDL2_image.a"
    )
    add_library(Libraries STATIC ${IMGUI})
    target_link_libraries(Libraries PRIVATE ${STATIC_LIBS})
    
    if(PLATFORM STREQUAL WIN)
        target_link_libraries(Libraries PRIVATE
            winmm
            imm32 
            version
            setupapi
        )
    else()
        message(FATAL_ERROR "SDL2 is invalid for current platform")
    endif()
else()
    message(FATAL_ERROR "Current RENDERER is invalid set")
endif()


 ######################### Include Folders #########################
target_include_directories(Libraries PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Libraries PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)