#pragma once
#include "Window/Window.h"
#include "Render/Render.h"

namespace PF {
  class Sandbox{
    private:
      Window *window;    
    public:
      Sandbox(Window *window);
      void run();
      void event(SDL_Event* event);
  };
};