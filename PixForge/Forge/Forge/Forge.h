#pragma once
#include "CoreForge/Window/Window.h"
#include "CoreForge/GUI/Gui.h"
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
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF::Forge