#include "PixGame.h"

int WinMain(){
  PC::Window window(WINDOWTITLE);
  PC::GameRunner gameRunner(&window);
  gameRunner.run();

  return 0;
}
 
namespace PC{

GameRunner::GameRunner(Window *window)
  :window(window) { 
    if(game.isEmpty() || settings.isEmpty()) throw std::runtime_error("Can't read game.bin or settings.bin");
    game.read(&hash);
    settings.read(&hash);
    if(saves.isEmpty()){
      saves.push("PixWorkshopGameSaves");
      saves.save(&hash);
    }
    else saves.read(&hash);
   }

GameRunner::~GameRunner(){
}
void GameRunner::run() {
  window->run();
}
}