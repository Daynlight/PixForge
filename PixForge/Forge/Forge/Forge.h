#pragma once
#include "Engine/Engine.h"
// #include "GUI/Gui.h"
// #include "Sandbox/Sandbox.h"
#include "Utilities/Log.h"

namespace PF::FORGE{
class Forge{
private:
  ENGINE::Engine engine;
  // Sandbox sandbox;
  // CoreForge::Gui gui;
  bool dragging = false;
  int lastX = 0, lastY = 0;
  void events();
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF::Forge