#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Objects/Object.h"
#include "STL/STL.h"

namespace PF {
  class Sandbox{
    private:
      Window *window;
      Vector<PF::Object*> *objects;
    public:
      Sandbox(Window *window, Vector<PF::Object*> *objects);
      void run();
      void event(SDL_Event* event);
  };
};