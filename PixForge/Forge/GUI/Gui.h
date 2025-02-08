#pragma once
#include "Window/Window.h"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

#include "Renderer/Objects/Manager.h"
#include "Ui/Manager.h"

#include "Tools/Log.h"

namespace PF::Forge{
class Gui{
private:
  Core::Window* window;
  Ui::Manager ui;
private:
  inline void renderDock();
  inline void renderTopBar();
public:
  Gui(const std::string &path, Core::Window* window, Core::Renderer::Objects::Manager* object);
  ~Gui();
  void renderGui();
  void guiEvent(SDL_Event* event);
};
}; // namespace PF::Forge