#pragma once
#include "Window/Window.h"
#include "STL/STL.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "Tools/Tools.h"

namespace PF{
  struct GuiWindow{ 
    static bool render(uint8_t type = 0);
    inline static bool log();
    inline static bool textEditor();
  };

  class Gui{
    private:
      Window* window;
      File gui_window = File("settings/gui_window.ini");
      inline void gui_window_open(uint8_t type);
      inline void renderDock();
      inline void renderTopBar();
    public:
      Gui(Window* window);
      ~Gui();
      void renderGui();
      void guiEvent(SDL_Event* event);
  };
};