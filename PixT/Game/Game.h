#pragma once
#include "../Assets/Assets.h"
#include "../Core/Window.h"
#include "../Core/Renderer.h"
#include "CONFIG.h"

namespace PG {
  class Game{
    private:
      PC::Window window = PC::Window(GAME_TITLE);    
    public:
      void run();
      void gameEvent();
  };
};