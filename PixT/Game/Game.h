#pragma once
#include "../Assets/Assets.h"
#include "../Core/Window.h"
#include "../Core/Renderer.h"
#include "CONFIG.h"

namespace PG {
  class Game{
    private:
      PC::Window *window;    
    public:
      Game(PC::Window *window);
      void run();
#ifdef BUILD
      void gameEvent();
#else
      void gameEvent(SDL_Event* event);
#endif
  };
};