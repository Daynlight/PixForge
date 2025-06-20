#include "Forge.h"

PF::FORGE::Forge::Forge() {
  Utilities::Log::log("Forge Created");
};

PF::FORGE::Forge::~Forge(){
  Utilities::Log::log("Forge Destroyed");
};

void PF::FORGE::Forge::run(){
  Utilities::Log::inf("Forge Running");
  // while (window.isRunning()){
  //   SDL_SetRenderDrawColor(window.getRenderer(),25,25,25,255); 
  //   SDL_RenderClear(window.getRenderer());
  //   gui.render();
  //   SDL_RenderPresent(window.getRenderer());
  //   events();
  // };
};

void PF::FORGE::Forge::events(){
  // SDL_Event event;
  // while(SDL_PollEvent(&event)){
  //   gui.guiEvent(event);
  //   window.windowEvent(event);
  // };
};