#include "Engine.h"

void PF::ENGINE::Engine::run(){
  renderer.pullEvents(events);
  for(size_t i = 0; i < events.size(); i++){
    EventsCodes event = events.pop();
    renderer.proccessEvent(event);
  };

  renderer.renderBackground({50, 50, 50, 255});

  renderer.renderColourBox({200, 200, 0, 200, 200}, {200, 0, 0, 255});
  renderer.render();
};
