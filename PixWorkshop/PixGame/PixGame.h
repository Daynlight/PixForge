#pragma once
#include "../Settings.h"
#include "../PixCore/PixCore.h"
#include "../vendor/Data/Data.h"

namespace PC{
class GameRunner{
  private:
    Window *window;
    Data::BaseHash hash = Data::BaseHash(HASHKEY);
    Data::File game = Data::File("game.bin");
  public:
    GameRunner(Window *window);
    ~GameRunner();
    void run();
};

}