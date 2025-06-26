#pragma once
#include "Engine/Engine.h"
// #include "GUI/Gui.h"
// #include "Sandbox/Sandbox.h"
#include "Utilities/Log.h"
#include "STL/Folder/Folder.h"

namespace PF::FORGE{
class Forge{
private:
  ENGINE::Engine engine;
  // Sandbox sandbox;
  // CoreForge::Gui gui;
  STL::File window_settings = STL::File("settings/window.ini");
  bool dragging = false;
  int lastX = 0, lastY = 0;
  void events();
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF::Forge