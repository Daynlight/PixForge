#include "Engine.h"

void PF::ENGINE::Engine::Init(const std::string &window_title, int width, int height){
  renderer = new PF::PLATFORM::Renderer();
  renderer->createWindow(window_title, width, height);
  renderer->createRenderer();
};

PF::ENGINE::Engine::~Engine() {
  delete renderer;
};

void PF::ENGINE::Engine::run(std::function<void()> func) {
  while (renderer->isRunning()){
    renderer->pullEventsAndProccessWindowEvents(events);
    for(size_t i = 0; i < events.size(); i++)
      event(events.pop());

    func();
  };
};

void PF::ENGINE::Engine::render(){
  renderer->render();
};

void PF::ENGINE::Engine::event(EventsCodes event) {

};

void PF::ENGINE::Engine::generateFrame(){
  renderer->renderBackground({50, 50, 50, 255});

  renderer->renderColourBox({200, 300, 0.9, 200, 200}, {0, 255, 0, 255});
  renderer->renderColourBox({200, 200, 0.6, 200, 200}, {200, 0, 0, 255});
};
