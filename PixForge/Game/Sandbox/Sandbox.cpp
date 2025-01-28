#include "Sandbox.h"

PG::Sandbox::Sandbox(PC::Window* window) :window(window){};

void PG::Sandbox::run(){
  PC::Renderer::background(window, 255, 20,12,255);


}

void PG::Sandbox::gameEvent(SDL_Event* event){

    window->windowEvent(*event);
};
