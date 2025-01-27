#pragma once
#include "Tools.h"
#include "../Core/STL.h"
#include "../Core/Window.h"
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_impl_sdl2.h"
#include "../vendor/imgui/imgui_impl_sdlrenderer2.h"

namespace PE{
  struct GuiWindow{ 
    static bool render(uint8_t type = 0);
    inline static bool log();
    inline static bool textEditor();
  };

  class Gui{
    private:
      PC::Window* window;
      PC::File gui_window = PC::File("settings/gui_window.ini");
      inline void gui_window_open(uint8_t type);
      inline void renderDock();
      inline void renderTopBar();
    public:
      Gui(PC::Window* window);
      ~Gui();
      void renderGui();
      void guiEvent(SDL_Event* event);
  };
};