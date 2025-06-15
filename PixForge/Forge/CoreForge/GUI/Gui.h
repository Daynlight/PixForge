#pragma once
#include "Window/Window.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_sdlrenderer2.h"

#include "Renderer/Objects/Manager.h"
#include "Ui/Manager.h"

#include "Utilities/Log.h"

namespace PF::Forge{
class Gui{
private:
  Core::Window* window;
  Ui::Manager ui;
private:
  inline void renderDock();
  inline void renderTopBar();
public:
  Gui(const std::string &path, Core::Window* window);
  ~Gui();
  void render();
  void guiEvent(SDL_Event* event);
};
}; // namespace PF::Forge