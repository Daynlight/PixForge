#pragma once
#include "../Macro.h"
#include "Settings.h"
#include "Assets.h"
#include "PCWindow.h"
#include "PCRenderer.h"

namespace PG {
  class Game{
    private:
      PC::Window window = PC::Window(GAME_TITLE);    
    public:
      void run();
      void gameEvent();
  };
}
