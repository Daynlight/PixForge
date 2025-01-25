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
  #ifdef _WIN32
    std::string buildCommand = "cmd.exe /C ..\\PixT\\PixGame\\scripts\\build.bat \""GAME_TITLE"\"";
  #else
    std::string buildCommand = "bash ../PixT/PixGame/scripts/build.sh '"GAME_TITLE"'";
  #endif
  int result = system(buildCommand.c_str());
  if (result == -1) return false;
  return true;
}

bool PE::Editor::runGame(){
  buildGame();
  #ifdef _WIN32
    std::string runCommand = "start /B cmd.exe /C ..\\PixT\\PixGame\\scripts\\run.bat \""GAME_TITLE"\"";
  #else
    std::string runCommand = "bash ../PixT/PixGame/scripts/run.sh '"GAME_TITLE"'";
  #endif
  system(runCommand.c_str());
  return true;
}
