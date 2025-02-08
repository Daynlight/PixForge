#include "Forge.h"

PF::Forge::Forge()
  :window("PixEditor"), textures("textures.bin", &window), objects("objects.bin", &textures, &window), 
  gui("settings/gui_window.ini", &window, &objects), sandbox(&window, &objects){
  Log::log("Window Created");
  Log::log("Objects Created");
  objects.load();
  Log::inf("Objects loaded: "+std::to_string(objects.objects.size()));
  Log::log("Texture Created");
  textures.load();
  Log::inf("Textures loaded: "+std::to_string(textures.size()));
  Log::log("Forge Created");
};

PF::Forge::~Forge(){
  objects.save();
  Log::inf("Objects saved: "+std::to_string(objects.objects.size()));
  Log::log("Objects Destroyed");
  textures.save();
  Log::inf("Textures saved: "+std::to_string(textures.size()));
  Log::log("Textures Destroyed");
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
    // [NOTE] this solution is not optimal
    if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) textures.load();

    sandbox.event(&event);
    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  };
};