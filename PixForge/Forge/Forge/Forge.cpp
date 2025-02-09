#include "Forge.h"

PF::Forge::Forge::Forge()
  :window("PixEditor"), textures("textures.bin", &window), objects("objects.bin", &window), 
  gui("settings/gui_window.ini", &window, &objects), sandbox(&window, &objects){
  Tools::Log::log("Window Created");
  Tools::Log::log("Objects Created");
  objects.load();
  Tools::Log::inf("Objects loaded: "+std::to_string(objects.objects.size()));
  Tools::Log::log("Texture Created");
  textures.load();
  Tools::Log::inf("Textures loaded: "+std::to_string(textures.size()));
  Tools::Log::log("Forge Created");
};

PF::Forge::Forge::~Forge(){
  objects.save();
  Tools::Log::inf("Objects saved: "+std::to_string(objects.objects.size()));
  Tools::Log::log("Objects Destroyed");
  textures.save();
  Tools::Log::inf("Textures saved: "+std::to_string(textures.size()));
  Tools::Log::log("Textures Destroyed");
  Tools::Log::log("Window Destroyed");
  Tools::Log::log("Forge Destroyed");
};

void PF::Forge::Forge::run(){
  Tools::Log::inf("Forge Running");
  while (window.isRunning()){
    Core::Renderer::background(&window, backgroundColour);

    sandbox.run();

    gui.renderGui();
    events();
    SDL_RenderPresent(window.getRenderer());
  };
};

inline void PF::Forge::Forge::events(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    // [NOTE] this solution is not optimal
    if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) textures.load();

    sandbox.event(&event);
    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  };
};