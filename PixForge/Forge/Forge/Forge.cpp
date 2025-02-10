#include "Forge.h"

PF::Forge::Forge::Forge()
  :window("PixEditor"), gui("settings/gui_window.ini", &window), sandbox(&window){
  Tools::Log::get().log("Window Created");
  Tools::Log::get().log("Objects Manager Created");
  
  Core::Renderer::Assets::init(&window);
  Core::Renderer::Objects::Manager::init("objects.bin", "textures.bin", &window);
  Core::Renderer::Objects::Manager::get().load();

  Tools::Log::get().log("Forge Created");
};

PF::Forge::Forge::~Forge(){
  Core::Renderer::Objects::Manager::get().save();
  Tools::Log::get().log("Objects Manager Destroyed");

  Tools::Log::get().log("Window Destroyed");
  Tools::Log::get().log("Forge Destroyed");

  
  Core::Renderer::Objects::Manager::get().dealloc();
  Core::Renderer::Assets::dealloc();
};

void PF::Forge::Forge::run(){
  Tools::Log::get().inf("Forge Running");
  while (window.isRunning()){
    Core::Renderer::Assets::background(backgroundColour);

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
    if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) 
      Core::Renderer::Objects::Manager::get().refreshAssets();

    sandbox.event(&event);
    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  };
};