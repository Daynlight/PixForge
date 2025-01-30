#include "Game.h"

int WinMain(){
  //[FEATURE] Get data from file and set Game Window Title
  PF::Window window = PF::Window("Game");
  PF::Game game = PF::Game(&window);
  game.run();
  
  return 0;
}