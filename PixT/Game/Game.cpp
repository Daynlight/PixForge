#include "Game.h"

void PG::Game::run(){
  while (window.isRunning()){
    PC::Renderer::background(&window, whiteColour);

    gameEvent();
    SDL_RenderPresent(window.getRenderer());
  }
}

void PG::Game::gameEvent(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){

    window.windowEvent(event);
  }
}
