#include "Forge.h"

PE::Forge::Forge(){
  Log::inf("Forge Created");
}

PE::Forge::~Forge(){
  Log::inf("Forge Destroyed");
}

void PE::Forge::run(){
  while (window.isRunning()){
    PC::Renderer::background(&window, backgroundColour);

    sandbox.run();

    gui.renderGui();
    events();
    SDL_RenderPresent(window.getRenderer());
  };
};

void PE::Forge::events(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_KEYDOWN){
      if(event.key.keysym.sym == SDLK_F5) Builder::buildGame();
      if(event.key.keysym.sym == SDLK_F6) Builder::runGame();
    }

    sandbox.gameEvent(&event);
    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  };
};