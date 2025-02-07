#include "Forge.h"

PF::Forge::Forge()
  :window("PixEditor"), sandbox(&window, &objects), ui(&objects), gui(&window, &ui){
  Log::inf("Forge Created");
  
  ui.load(&gui_window);
  objects.load(&objects_file);
};

PF::Forge::~Forge(){
  objects.save(&objects_file);
  ui.save(&gui_window);
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