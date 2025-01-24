#include "PixGame.h"

void PG::Game::run(){
  while (window.isRunning()){
    PC::Renderer::background(&window, backgroundColour);

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
