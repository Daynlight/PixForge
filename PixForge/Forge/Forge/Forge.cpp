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
    if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_RESIZED) Core::Renderer::Objects::Manager::refreshAssets();
    editorMovement(event);
    sandbox.event(&event);
    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  };
};

void PF::Forge::Forge::editorMovement(const SDL_Event &event) {
  if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_MIDDLE) {
    dragging = true;
    lastX = event.button.x;
    lastY = event.button.y;
  }
  else if(event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_MIDDLE) dragging = false;
  else if(event.type == SDL_MOUSEMOTION && dragging) {
    int deltaX = event.motion.x - lastX;
    int deltaY = event.motion.y - lastY;
    Core::Renderer::Assets::getRefWorldPosition()[0] -= deltaX;
    Core::Renderer::Assets::getRefWorldPosition()[1] -= deltaY;
    lastX = event.motion.x;
    lastY = event.motion.y;
  };
};