#include "Engine.h"

void PF::ENGINE::Engine::Init(const std::string &window_title){
  renderer = new PF::PLATFORM::Renderer();
  renderer->createWindow(window_title, "settings/window.ini");
  renderer->createRenderer();
  editor_gui = new PLATFORM::EditorGui("settings/editor_gui.ini", renderer);
};

PF::ENGINE::Engine::~Engine() {
  delete editor_gui; 
  delete renderer;
};

void PF::ENGINE::Engine::run(){
  renderer->pullEvents(events);
  for(size_t i = 0; i < events.size(); i++){
    EventsCodes event = events.pop();
    renderer->proccessEvent(event);
  };

  renderer->renderBackground({50, 50, 50, 255});

  renderer->renderColourBox({200, 300, 0.9, 200, 200}, {0, 255, 0, 255});
  renderer->renderColourBox({200, 200, 0.6, 200, 200}, {200, 0, 0, 255});
  renderer->render();
};
