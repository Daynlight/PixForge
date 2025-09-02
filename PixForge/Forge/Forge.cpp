#include "Forge.h"

PF::FORGE::Forge::Forge() 
  : allocs(new PF::Utilities::Benchmark::Allocs("Program Allocs")) {
  PF::Utilities::Benchmark::Timer("Startup Time");

  Utilities::Log::log("Forge Created");
  UTILITIES::Folder settings_folder("settings");

  if(!settings_folder.exist()) settings_folder.create();
  window_settings.clear();
  window_settings.read();

  renderer = new FORGE::Renderer();
  renderer->createWindow("PixForge Editor", 800, 600);
  renderer->createRenderer();
  gui = new FORGE::Gui("settings/editor_gui.ini", renderer);

  PF::UTILITIES::Vector<std::string> renderers = engine.getRenderers();
  for(unsigned int i = 0; i < renderers.size(); i++)
    PF::Utilities::Log::inf("Renderer: " + renderers[i]);

  engine.loadRenderer(renderers[0]);
  // engine.InitForEditor("Game Window", 800, 600);
};

PF::FORGE::Forge::~Forge(){
  UTILITIES::Vec<int, 4> window_rect = renderer->getWindowRect();
  window_settings.clear();
  window_settings.push(std::to_string(window_rect[2]));
  window_settings.push(std::to_string(window_rect[3]));
  window_settings.save();

  delete gui;
  delete renderer;
  delete allocs;
  PF::Utilities::Log::get().save();
};

void PF::FORGE::Forge::run(){
  Utilities::Log::inf("Forge Running");
  while(renderer->isRunning()){
    
    renderer->renderBackground({50, 50, 50, 255});
    gui->render();
    renderer->render();
    renderer->events();
    
    // engine.events();
    // // engine.generateFrame();
    // // GLuint* engineTxt = engine.renderEditorWindow();
    // engine.render();
    
  };
};