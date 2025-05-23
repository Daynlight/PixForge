#include "Forge.h"

PF::Forge::Forge::Forge()
  :window("PixEditor"), gui("settings/gui_window.ini", &window), sandbox(&window){
  Tools::Log::init();
  Tools::Log::log("Window Created");
  Core::Renderer::Assets::init(&window);
  loadSettings();
  Tools::Log::log("Assets Initialized");
  Core::Renderer::Objects::Manager::init("objects.bin", "textures.bin", &window);
  Core::Renderer::Objects::Manager::load();
  Tools::Log::log("Objects Initialized");
  Tools::Log::log("Forge Created");
};

PF::Forge::Forge::~Forge(){
  Core::Renderer::Objects::Manager::save();
  saveSettings();
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

void PF::Forge::Forge::loadSettings() {
  STL::Folder window_settings("settings/");
  if(!window_settings.exist()) window_settings.create();
  STL::File settings = window_settings.openFile("editor_settings.ini");
  if(settings.exist()){
    settings.read();
    if(settings.size() > 0){
      STL::Vec<int,4> world_pos;
      STL::Vector<std::string>* record = settings.split(';')[0];
      for(int i = 0; i < 4; i++) world_pos[i] = std::stoi((*record)[i]);
      Core::Renderer::Assets::getRefWorldPosition() = world_pos;
    }
  };
};

void PF::Forge::Forge::saveSettings() {
  STL::Folder window_settings("settings/");
  if(!window_settings.exist()) window_settings.create();
  STL::File settings = window_settings.openFile("editor_settings.ini");
  if(!settings.exist()) settings.create();
  STL::Vector<std::string> world_pos;
  for(int i = 0; i < 4; i++) world_pos.push(std::to_string(Core::Renderer::Assets::getRefWorldPosition().data[i]));
  settings.push(world_pos.concat(';'));
  settings.save();
};