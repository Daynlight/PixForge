#pragma once
#include "Core.h"
#include "CoreForge/Window/Window.h"
#include "Utilities/Log.h"

namespace PF {
class Sandbox{
private:
  CoreForge::Window *forgeWindow;
  SDL_Texture* renderTexture = nullptr;
public:
  Sandbox(CoreForge::Window *window);
  ~Sandbox();
  SDL_Texture* getViewportTexture();
  void event();
};
}; // namespace PF