#pragma once
#include "CoreForge/Window/Window.h"
#include "SDL2_image/SDL_image.h"

#include "CoreForge/Gui/Gui.h"
#include "Sandbox/Sandbox.h"

#include "Utilities/Log.h"

namespace PF::Forge{
class Forge{
private:
  CoreForge::Window window;
  Sandbox sandbox;
  CoreForge::Gui gui;
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