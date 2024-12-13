#include "PixEditor.h"

int WinMain(){
  PC::Window window(WINDOWTITLE);
  PC::Editor editor(&window);
  editor.run();

  return 0;
}

namespace PC{

Editor::Editor(Window *window)
  :window(window) {
    if(game.isEmpty()) {
      game.push("PixWorkshopGameFile");
      game.save(&hash);
    }
    else game.read(&hash);
    if(settings.isEmpty()){
      settings.push("PixWorkshopGameSettings");
      settings.save(&hash);
    }
    else settings.read(&hash);
    if(saves.isEmpty()){
      saves.push("PixWorkshopGameSaves");
      saves.save(&hash);
    }
    else saves.read(&hash);
   }

Editor::~Editor(){
  game.save(&hash);
}
void Editor::run() {

  window->run();
}
}