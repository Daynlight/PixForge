#pragma once
#include "Engine/Gui/ImGuiEngine.h"
#include "Sandbox/Sandbox.h"
#include "Utilities/Log.h"

namespace PF::CoreForge{
class Gui{
private:
  CoreForge::Window *window;
  Sandbox *sandbox;
  Engine::ImGuiEngine imGui;
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