#pragma once
#include "Window/Window.h"
#include "CoreForge/Window/Window.h"
#include "Renderer/Objects/Manager.h"
#include "Utilities/Log.h"

namespace PF {
class Sandbox{
private:
  // Core::Window window("Sandbox");
  CoreForge::Window *forgeWindow;
  SDL_Texture* renderTexture = nullptr;
public:
  Sandbox(CoreForge::Window *window);
  ~Sandbox();
  SDL_Texture* getViewportTexture();
  // Core::Window *getWindow() { return &window; };
  void event();
};
}; // namespace PF