#pragma once
#include "Settings.h"
#include "../Assets/Assets.h"
#include "../Core/Window.h"
#include "../Core/Renderer.h"

namespace PG {
  class Game{
    private:
      PC::Window window = PC::Window(GAME_TITLE);    
    public:
      void run();
      void gameEvent();
  };
}
