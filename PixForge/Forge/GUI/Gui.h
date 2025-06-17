#pragma once
#include "Sandbox/Sandbox.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl2.h"
#include "imgui/imgui_impl_sdlrenderer2.h"
#include "Utilities/Log.h"

namespace PF::CoreForge{
class Gui{
private:
  CoreForge::Window *window;
  Sandbox *sandbox;
private:
  inline void renderDock();
  inline void renderTopBar();
public:
  Gui(const std::string &path, CoreForge::Window* window, Sandbox *sandbox);
  ~Gui();
  void render();
  void guiEvent(SDL_Event event);
};
}; // namespace PF::CoreForge