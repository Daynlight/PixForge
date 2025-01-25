#pragma once
#include "../Macro.h"
#include "Settings.h"
#include "Assets.h"
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"
#include "PCRenderer.h"
#include "PCWindow.h"
#include <cstdlib>

namespace PE{
  class Editor{
    private:
      PC::Window window = PC::Window("PixEditor");  
      void imGuiDock();
      void renderGui();
      void editorEvent();
      bool buildGame(); 
      bool runGame();
    public:
      Editor();
      void run();
  };
};