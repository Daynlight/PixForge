#pragma once
#include "../../Core/Window/Window.h"
#include "../../Core/Render/Render.h"

namespace PF {
  class Sandbox{
    private:
      Window *window;    
    public:
      Sandbox(Window *window);
      void run();
      void gameEvent(SDL_Event* event);
  };
};