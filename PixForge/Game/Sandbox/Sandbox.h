#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Objects/Object.h"
#include "STL/STL.h"

namespace PF {
  class Sandbox{
    private:
      Window *window;
      ObjectManager *objects;
    public:
      Sandbox(Window *window, ObjectManager *objects);
      void run();
      void event(SDL_Event* event);
  };
};