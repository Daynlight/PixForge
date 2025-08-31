#include "Forge.h"

PF::FORGE::Forge::Forge() 
  : allocs(new PF::Utilities::Benchmark::Allocs("Program Allocs")) {
  Utilities::Log::log("Forge Created");
  UTILITIES::Folder settings_folder("settings");
  if(!settings_folder.exist()) settings_folder.create();
  window_settings.clear();
  window_settings.read();
  
  engine.Init("PixForge Editor", 800, 600);

  editor_gui = new PLATFORM::EditorGui("settings/editor_gui.ini", engine.getRenderer());
};

PF::FORGE::Forge::~Forge(){
  UTILITIES::Vec<int, 4> window_rect = engine.getWindowRect();
  window_settings.clear();
  window_settings.push(std::to_string(window_rect[2]));
  window_settings.push(std::to_string(window_rect[3]));
  window_settings.save();
  delete editor_gui;
  delete allocs;
  PF::Utilities::Log::get().save();
};

void PF::FORGE::Forge::run(){
  Utilities::Log::inf("Forge Running");
  engine.run([&](){
    engine.generateFrame();
    editor_gui->render();
    engine.render();
  });
};

void PF::FORGE::Forge::events(){
  // SDL_Event event;
  // while(SDL_PollEvent(&event)){
  //   gui.guiEvent(event);
  //   window.windowEvent(event);
  // };
};