#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Renderer/Objects/ObjectManager.h"
#include "Tools/Log.h"

namespace PF {
class Sandbox{
private:
  Window *window;
  ObjectManager *objects;
public:
  Sandbox(Window *window, ObjectManager *objects) : window(window), objects(objects) { Log::log("Sandbox Created"); };
  void run();
  void event(SDL_Event* event);
};
}; // namespace PF