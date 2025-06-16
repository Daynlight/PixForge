#pragma once
#include "Window/Window.h"
#include "Renderer/Objects/Manager.h"
#include "Utilities/Log.h"

namespace PF {
class Sandbox{
private:
  Core::Window window;
  SDL_Texture* renderTexture = nullptr;
public:
  Sandbox();
  ~Sandbox();
  SDL_Texture* render();
  Core::Window *getWindow() { return &window; };
  void event();
};
}; // namespace PF