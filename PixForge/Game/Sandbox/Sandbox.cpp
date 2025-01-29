#include "Sandbox.h"

PF::Sandbox::Sandbox(Window* window) :window(window){};

void PF::Sandbox::run(){
  Renderer::background(window, 255, 20,12,255);


}

void PF::Sandbox::gameEvent(SDL_Event* event){

    window->windowEvent(*event);
};
