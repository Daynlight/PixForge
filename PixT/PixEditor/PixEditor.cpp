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
    }

    window.windowEvent(event);
  }
}

bool PE::Editor::buildGame(){
  std::string buildCommand = "bash ../PixT/PixEditor/buildscript.sh " + std::string(GAME_TITLE);

  // Run the build command
  int result = system(buildCommand.c_str());

  if (result == -1) return false;
  return true;
}
