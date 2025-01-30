#pragma once
#include "Window/Window.h"
#include "Render/Render.h"

namespace PF {
  class Game{
    private:
      Window *window;    
    public:
      Game(Window *window);
      void run();
      void event();
  };
};