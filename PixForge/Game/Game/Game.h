#pragma once
#include "Assets/Assets.h"
#include "../../Core/Window/Window.h"
#include "../../Core/Render/Render.h"
#include "CONFIG.h"

namespace PG {
  class Game{
    private:
      PC::Window *window;    
    public:
      Game(PC::Window *window);
      void run();
      void gameEvent();
  };
};