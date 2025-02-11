#pragma once
#include "Window/Window.h"
#include "../vendor/SDL2_image/SDL_image.h"

#include "Gui/Gui.h"
#include "Sandbox.h"
#include "Renderer/Objects/Manager.h"
#include "Renderer/Assets.h"

#include "Tools/Log.h"

namespace PF::Forge{
class Forge{
private:
  Core::Window window;
  Sandbox sandbox;
  Gui gui;
private:
  inline void events();
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF::Forge