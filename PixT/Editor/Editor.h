#pragma once
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_sdl2.h"
#include "../vendor/imgui/imgui_impl_sdlrenderer2.h"
#include "../vendor/data/Data.h"
#include "../Assets/Settings.h"
#include "../Assets/Assets.h"
#include "../Core/Renderer.h"
#include "../Core/Window.h"
#include <cstdlib>

namespace PE{
  class Editor{
    private:
      PC::Window window = PC::Window("PixEditor");  
      void imGuiDock();
      void renderGui();
      void editorEvent();
      void buildGame(); 
      void runGame();
      std::string game_title = GAME_TITLE;
    public:
      Editor();
      ~Editor();
      void run();
  };
};