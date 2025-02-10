#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Renderer/Objects/Manager.h"
#include "Tools/Log.h"

namespace PF {
class Sandbox{
private:
  Core::Window *window;
public:
  Sandbox(Core::Window *window) : window(window) { Tools::Log::get().log("Sandbox Created"); };
  void run();
  void event(SDL_Event* event);
};
}; // namespace PF