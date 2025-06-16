#include "Forge.h"

PF::Forge::Forge::Forge()
  :window("settings/window.ini", "PixEditor"), sandbox(&window), gui("settings/gui.ini", &window, &sandbox) {
  Utilities::Log::log("Forge Created");
};

PF::Forge::Forge::~Forge(){
  Utilities::Log::log("Forge Destroyed");
};

void PF::Forge::Forge::run(){
  Utilities::Log::inf("Forge Running");
  while (window.isRunning()){
    SDL_SetRenderDrawColor(window.getRenderer(),25,25,25,255); 
    SDL_RenderClear(window.getRenderer());
    gui.render();
    SDL_RenderPresent(window.getRenderer());
    events();
  };
};

void PF::Forge::Forge::events(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    gui.guiEvent(event);
    window.windowEvent(event);
  };
};