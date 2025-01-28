#include "Game.h"

PG::Game::Game(PC::Window* window) :window(window){};

void PG::Game::run(){
  while (window->isRunning()){
  PC::Renderer::background(window, 255, 20,12,255);



    gameEvent();
    SDL_RenderPresent(window->getRenderer());
  };
};

void PG::Game::gameEvent(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){


    window->windowEvent(event);
  };
};