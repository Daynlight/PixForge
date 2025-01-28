#pragma once
#include "../../Core/Window/Window.h"
#include "../../Core/Render/Render.h"

namespace PG {
  class Sandbox{
    private:
      PC::Window *window;    
    public:
      Sandbox(PC::Window *window);
      void run();
      void gameEvent(SDL_Event* event);
  };
};