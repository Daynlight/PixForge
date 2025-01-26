#pragma once
#include "Tools.h"
#include "../vendor/data/Data.h"
#include "../Core/Window.h"
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_sdl2.h"
#include "../vendor/imgui/imgui_impl_sdlrenderer2.h"
#include <array>

namespace PE{
  struct GuiWindow{ 
    uint8_t type = 0;
    GuiWindow(uint8_t type = 0);
    bool render();
    bool log();
  };

  class Gui{
    private:
      PC::Window* window;
      Data::File gui_window_file = Data::File("gui_window.ini");
      std::array<GuiWindow, 5> gui_window;
      void gui_window_open(uint8_t type);
    public:
      Gui(PC::Window* window);
      ~Gui();
      void imGuiDock();
      void renderGui();
      void renderTopBar();
  };
};