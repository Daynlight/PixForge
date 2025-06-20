#include "Engine.h"

PF::ENGINE::Engine::Engine(){
}

void PF::ENGINE::Engine::run(){
  renderer.pullEvents(events);
  for(size_t i = 0; i < events.size(); i++){
    EventsCodes event = events.pop();
    renderer.proccessEvent(event);
  }
}
