#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Renderer/Objects/Manager.h"
#include "Tools/Log.h"

namespace PF {
class Sandbox{
private:
  Core::Window *window;
  Core::Renderer::Objects::Manager *objects;
public:
  Sandbox(Core::Window *window, Core::Renderer::Objects::Manager *objects) : window(window), objects(objects) { Tools::Log::log("Sandbox Created"); };
  void run();
  void event(SDL_Event* event);
};
}; // namespace PF