#include "Game.h"

PG::Game::Game(PC::Window* window) :window(window){};

void PG::Game::run(){
  #ifdef BUILD
    while (window->isRunning()){
  #endif
    PC::Renderer::background(window, 255, 20,12,255);



    #ifdef BUILD
      gameEvent();
      SDL_RenderPresent(window->getRenderer());
    }
    #endif
}

#ifdef BUILD
void PG::Game::gameEvent(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
#else
void PG::Game::gameEvent(SDL_Event* event){
#endif


#ifdef BUILD
    window->windowEvent(event);
  }
#endif
}
