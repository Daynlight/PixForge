#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Objects/ObjectManager.h"

#include "Sandbox.h"

#include "Gui/Gui.h"

#include "Tools/Log.h"
#include "Settings.h"

namespace PF{
class Forge{
private:
  Window window;
  Sandbox sandbox;
  Gui gui;
  ObjectManager objects;
private:
  inline void events();
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF