#pragma once
#include "Window/Window.h"
#include "Renderer/Objects/Manager.h"
#include "Utilities/Log.h"

namespace PF {
class Sandbox{
private:
  Core::Window *window;
public:
  Sandbox(Core::Window *window) : window(window) { Utilities::Log::log("Sandbox Created"); };
  void render();
  void event();
};
}; // namespace PF