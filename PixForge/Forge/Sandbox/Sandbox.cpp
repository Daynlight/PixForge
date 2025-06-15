#include "Sandbox.h"

void PF::Sandbox::run(){
    for(size_t i = 0; i < Core::Renderer::Objects::Manager::size(); i++) Core::Renderer::Objects::Manager::at(i).render(window);
}

void PF::Sandbox::event(SDL_Event* event){
    
};