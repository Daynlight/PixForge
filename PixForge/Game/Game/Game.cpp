#include "Game.h"

PF::Game::Game(Window* window) :window(window){};

void PF::Game::run(){
  while (window->isRunning()){
    Renderer::background(window, 255, 20,12,255);



    gameEvent();
    SDL_RenderPresent(window->getRenderer());
  };
};

void PF::Game::gameEvent(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){


    window->windowEvent(event);
  };
};