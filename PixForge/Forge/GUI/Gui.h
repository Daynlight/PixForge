#pragma once
#include "Window/Window.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "Tools/Log.h"
#include "Ui/Ui.h"

namespace PF{
class Gui{
private:
  Window* window;
  UIManager* ui;
private:
  inline void renderDock();
  inline void renderTopBar();
public:
  Gui(Window* window, UIManager* ui);
  ~Gui();
  void renderGui();
  void guiEvent(SDL_Event* event);
};
}; // namespace PF