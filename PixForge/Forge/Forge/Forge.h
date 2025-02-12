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
  bool dragging = false;
  int lastX = 0, lastY = 0;
private:
  inline void events();
  inline void editorMovement(const SDL_Event &event);
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF::Forge