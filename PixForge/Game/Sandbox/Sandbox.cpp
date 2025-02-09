#include "Sandbox.h"

void PF::Sandbox::run(){
    for(size_t i = 0; i < Core::Renderer::Objects::Manager::get().size(); i++) Core::Renderer::Objects::Manager::get()[i].render(window);
}

void PF::Sandbox::event(SDL_Event* event){
    window->windowEvent(*event);
};