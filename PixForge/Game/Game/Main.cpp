#include "Game.h"

int WinMain(){
  PC::Window window = PC::Window(GAME_TITLE);
  PG::Game game = PG::Game(&window);
  game.run();
  
  return 0;
}