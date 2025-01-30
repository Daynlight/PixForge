#include "Sandbox.h"

PF::Sandbox::Sandbox(Window* window) :window(window){};

void PF::Sandbox::run(){

}

void PF::Sandbox::event(SDL_Event* event){
    window->windowEvent(*event);
};
