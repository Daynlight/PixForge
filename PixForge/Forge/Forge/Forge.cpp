#include "Forge.h"

PF::Forge::Forge()
  :window("PixEditor"), objects("objects.bin"), gui("settings/gui_window.ini", &window, &objects), sandbox(&window, &objects){
  Log::log("Window Created");
  Log::log("Objects Created");
  objects.load();
  Log::inf("Objects loaded: "+std::to_string(objects.objects.size()));
  Log::log("Forge Created");
};

PF::Forge::~Forge(){
  objects.save();
  Log::inf("Objects saved: "+std::to_string(objects.objects.size()));
  Log::log("Objects Destroyed");
  Log::log("Window Destroyed");
  Log::log("Forge Destroyed");
};

void PF::Forge::run(){
  Log::inf("Forge Running");
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