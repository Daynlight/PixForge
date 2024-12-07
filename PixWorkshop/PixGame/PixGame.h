#pragma once
#include "../Settings.h"
#include "../PixCore/PixCore.h"

namespace PC{
class GameRunner{
  private:
    Window *window;
  public:
    GameRunner(Window *window);
    ~GameRunner();
    void run();
};

}