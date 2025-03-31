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
  bool dragging = false;
  int lastX = 0, lastY = 0;
  void events();
  void editorMovement(const SDL_Event &event);
  inline void loadSettings();
  inline void saveSettings();
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF::Forge