#pragma once
#include "Window/Window.h"
#include "STL/STL.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "Tools/Tools.h"

namespace PF{
  struct GuiWindow{ 
    static bool render(uint8_t type = 0, Folder* folder = nullptr);
    inline static bool log();
    inline static bool textEditor();
    inline static bool fileExplorer(Folder *folder);
  };

  class Gui{
    private:
      Window* window;
      File gui_window = File("settings/gui_window.ini");
      Folder *assets_folder;
      inline void gui_window_open(uint8_t type);
      inline void renderDock();
      inline void renderTopBar();
    public:
      Gui(Window* window, Folder *assets_folder);
      ~Gui();
      void renderGui();
      void guiEvent(SDL_Event* event);
  };
};