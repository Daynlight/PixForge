#include "Forge.h"

PF::Forge::Forge()
  :window("PixEditor"), objects("objects.bin"), sandbox(&window, &objects), gui("settings/gui_window.ini", &window, &objects){
  Log::inf("Forge Created");
  objects.load();
};

PF::Forge::~Forge(){
  objects.save();
  Log::inf("Forge Destroyed");
};

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

    sandbox.event(&event);
    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  };
};