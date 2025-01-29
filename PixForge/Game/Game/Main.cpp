#include "Game.h"

int WinMain(){
  PF::Window window = PF::Window(GAME_TITLE);
  PF::Game game = PF::Game(&window);
  game.run();
  
  return 0;
}