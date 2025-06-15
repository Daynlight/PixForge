#pragma once
#include "Window/Window.h"
#include "SDL2_image/SDL_image.h"

#include "CoreForge/Gui/Gui.h"
#include "Sandbox/Sandbox.h"
#include "Renderer/Objects/Manager.h"
#include "Renderer/Assets.h"

#include "Utilities/Tools/Log.h"

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