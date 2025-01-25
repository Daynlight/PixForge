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
  std::string buildCommand = "bash ../PixT/PixGame/scripts/build.sh "GAME_TITLE;
  int result = system(buildCommand.c_str());
  if (result == -1) return false;
  return true;
}

bool PE::Editor::runGame(){
  std::string runCommand = "bash ../PixT/PixGame/scripts/run.sh "GAME_TITLE;
  int result = system(runCommand.c_str());
  return true;
}