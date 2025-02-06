#include "Sandbox.h"

PF::Sandbox::Sandbox(Window* window, Vector<PF::Object*> *objects) :window(window), objects(objects) {};

void PF::Sandbox::run(){
    for(size_t i = 0; i < objects->size(); i++) (*objects)[i]->render(window);
}

void PF::Sandbox::event(SDL_Event* event){
    window->windowEvent(*event);
};
