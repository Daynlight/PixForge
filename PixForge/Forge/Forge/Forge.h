#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Objects/Object.h"

#include "Sandbox.h"

#include "Gui/Gui.h"
#include "Gui/Ui/Ui.h"

#include "Tools/Log.h"
#include "Settings.h"

namespace PF{
class Forge{
private:
  Window window;
  Sandbox sandbox;
  Gui gui;
  UIManager ui;
  ObjectManager objects;
private:
  File objects_file = File("objects.bin");
  File gui_window = File("settings/gui_window.ini");
private:
  inline void events();
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF