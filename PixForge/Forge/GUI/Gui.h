#pragma once
#include "Window/Window.h"
#include "STL/STL.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "Tools/Tools.h"

namespace PF{
  struct GuiWindow{ 
    static bool render(uint8_t type = 0, Vector<std::string> *fileList = nullptr);
    inline static bool log();
    inline static bool textEditor();
    inline static bool fileExplorer(Vector<std::string> *fileList);
  };

  class Gui{
    private:
      Window* window;
      File gui_window = File("settings/gui_window.ini");
      Vector<std::string> *assets_list;
      inline void gui_window_open(uint8_t type);
      inline void renderDock();
      inline void renderTopBar();
    public:
      Gui(Window* window, Vector<std::string> *assets_list);
      ~Gui();
      void renderGui();
      void guiEvent(SDL_Event* event);
  };
};