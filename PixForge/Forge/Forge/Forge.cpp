#include "Forge.h"

PF::FORGE::Forge::Forge() {
  Utilities::Log::log("Forge Created");
  STL::Folder settings_folder("settings");
  if(!settings_folder.exist()) settings_folder.create();
  window_settings.clear();
  window_settings.read();
  if(window_settings.size() != 2)
    engine.Init("PixForge Editor", 800, 600);
  else
    engine.Init("PixForge Editor", std::stoi(window_settings[0]), std::stoi(window_settings[1]));

  editor_gui = new PLATFORM::EditorGui("settings/editor_gui.ini", engine.getRenderer());
};

PF::FORGE::Forge::~Forge(){
  STL::Vec<int, 4> window_rect = engine.getWindowRect();
  window_settings.clear();
  window_settings.push(std::to_string(window_rect[2]));
  window_settings.push(std::to_string(window_rect[3]));
  window_settings.save();
  Utilities::Log::log("Window Settings Saved");
  delete editor_gui;
  Utilities::Log::log("Forge Destroyed");
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