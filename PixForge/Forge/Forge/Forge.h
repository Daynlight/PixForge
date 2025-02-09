#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "../vendor/SDL2_image/SDL_image.h"

#include "Gui/Gui.h"
#include "Sandbox.h"
#include "Renderer/Objects/Manager.h"

#include "Tools/Log.h"
#include "Settings.h"

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