#include "Game.h"

PF::Game::Game(Window* window) :window(window){};

void PF::Game::run(){
  while (window->isRunning()){

    event();
    SDL_RenderPresent(window->getRenderer());
  };
};

void PF::Game::event(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){

    window->windowEvent(event);
  };
};