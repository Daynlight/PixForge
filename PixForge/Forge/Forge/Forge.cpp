#include "Forge.h"

PF::Forge::Forge()
  :window("PixEditor"), sandbox(&window), gui(&window){
  Log::inf("Forge Created");

  if(!assets_folder.exist()){
    assets_folder.createFolder();
    Log::war("Assets folder created");
  }
  assets_folder.fetchList();

  if(!texture_folder.exist()){
    texture_folder.createFolder();
    Log::war("Texture folder created");
  }
  texture_folder.fetchList();
}

PF::Forge::~Forge(){
  Log::inf("Forge Destroyed");
}

void PF::Forge::run(){
  while (window.isRunning()){
    Renderer::background(&window, backgroundColour);

    sandbox.run();

    gui.renderGui();
    events();
    SDL_RenderPresent(window.getRenderer());
  };
};

inline void PF::Forge::events(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_KEYDOWN){
      if(event.key.keysym.sym == SDLK_F5) Builder::buildGame();
      if(event.key.keysym.sym == SDLK_F6) Builder::runGame();
    }

    sandbox.event(&event);
    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  };
};