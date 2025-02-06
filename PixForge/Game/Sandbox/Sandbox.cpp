#include "Sandbox.h"

PF::Sandbox::Sandbox(Window* window, ObjectManager *objects) :window(window), objects(objects) {};

void PF::Sandbox::run(){
    for(size_t i = 0; i < objects->objects.size(); i++) (*objects).objects[i]->render(window);
}

void PF::Sandbox::event(SDL_Event* event){
    window->windowEvent(*event);
};
