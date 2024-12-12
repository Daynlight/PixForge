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
    
   }

Editor::~Editor(){
}
void Editor::run() {

  window->run();
}
}