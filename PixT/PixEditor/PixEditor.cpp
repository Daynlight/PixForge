#include "PixEditor.h"

void PE::Editor::run() {

  while (window.isRunning()){
    PC::Renderer::background(&window, backgroundColour);

    editorEvent();
    SDL_RenderPresent(window.getRenderer());
  }
}

void PE::Editor::editorEvent(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_KEYDOWN){
      if(event.key.keysym.sym == SDLK_F5) buildGame();
      if(event.key.keysym.sym == SDLK_F6) runGame();
    }

    window.windowEvent(event);
  }
}

bool PE::Editor::buildGame(){
  const char* buildCommand = "bash ../PixT/PixGame/scripts/build.sh '"GAME_TITLE"'";
  int result = system(buildCommand);
  if (result == -1) return false;
  return true;
}

bool PE::Editor::runGame(){
  const char* runCommand = "bash ../PixT/PixGame/scripts/run.sh '"GAME_TITLE"'";
  int result = system(runCommand);
  return true;
}