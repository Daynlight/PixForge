#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Objects/ObjectManager.h"
namespace PF {
class Sandbox{
private:
  Window *window;
  ObjectManager *objects;
public:
  Sandbox(Window *window, ObjectManager *objects) : window(window), objects(objects) {};
  void run();
  void event(SDL_Event* event);
};
}; // namespace PF