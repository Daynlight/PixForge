#pragma once
#include "Platforms/Platform.h"
#include "Engine/Engine.h"
// #include "GUI/Gui.h"
// #include "Sandbox/Sandbox.h"
#include "Forge/Log.h"
#include "Utilities/Folder/Folder.h"

namespace PF::FORGE{
class Forge{
private:
  ENGINE::Engine engine;
  // Sandbox sandbox;
  // CoreForge::Gui gui;
  PLATFORM::iEditorGui* editor_gui = nullptr;
  UTILITIES::File window_settings = UTILITIES::File("settings/window.ini");
  bool dragging = false;
  int lastX = 0, lastY = 0;
  void events();
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF::Forge