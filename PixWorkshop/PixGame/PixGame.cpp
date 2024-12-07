#include "PixGame.h"

int WinMain(){
  PC::Window window(WINDOWTITLE);
  PC::GameRunner gameRunner(&window);
  gameRunner.run();

  return 0;
}

namespace PC{

GameRunner::GameRunner(Window *window)
  :window(window) { }

GameRunner::~GameRunner(){
}
void GameRunner::run() {
  window->run();
}
}