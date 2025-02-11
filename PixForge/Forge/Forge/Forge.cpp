#include "Forge.h"

PF::Forge::Forge::Forge()
  :window("PixEditor"), gui("settings/gui_window.ini", &window), sandbox(&window){
  Tools::Log::init();
  Tools::Log::log("Window Created");
  
  Core::Renderer::Assets::init(&window);
  Tools::Log::log("Assets Initialized");

  Core::Renderer::Objects::Manager::init("objects.bin", "textures.bin", &window);
  Core::Renderer::Objects::Manager::load();
  Tools::Log::log("Objects Initialized");

  Tools::Log::log("Forge Created");
};

PF::Forge::Forge::~Forge(){
  Core::Renderer::Objects::Manager::save();
  Tools::Log::log("Objects Saved");

  Tools::Log::log("Window Destroyed");
  Tools::Log::log("Forge Destroyed");
};

void PF::Forge::Forge::run(){
  Tools::Log::inf("Forge Running");
  while (window.isRunning()){
    Core::Renderer::Assets::background(backgroundColour);

    sandbox.run();
    gui.render();

    events();
    
    SDL_RenderPresent(window.getRenderer());
  };
};

void PF::Forge::Forge::events(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    // [NOTE] this solution is not optimal
    if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) 
      Core::Renderer::Objects::Manager::refreshAssets();
    
    // Mouse Wheel down
    if(event.type == SDL_MOUSEWHEEL){
      Core::Renderer::Assets::getRefWorldPosition()[0] += event.wheel.x * MOUSEWHEELSPEED;
      Core::Renderer::Assets::getRefWorldPosition()[1] += event.wheel.y * MOUSEWHEELSPEED;
    };

    sandbox.event(&event);
    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  };
};