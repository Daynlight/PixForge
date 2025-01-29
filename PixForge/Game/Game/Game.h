#pragma once
#include "Assets/Assets.h"
#include "../../Core/Window/Window.h"
#include "../../Core/Render/Render.h"
#include "CONFIG.h"

namespace PF {
  class Game{
    private:
      Window *window;    
    public:
      Game(Window *window);
      void run();
      void gameEvent();
  };
};