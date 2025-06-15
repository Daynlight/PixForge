#include "Sandbox.h"

void PF::Sandbox::render(){
    Core::Renderer::Assets::background(backgroundColour);
    for(size_t i = 0; i < Core::Renderer::Objects::Manager::size(); i++) Core::Renderer::Objects::Manager::at(i).render(window);
    SDL_RenderPresent(window->getRenderer());
}

void PF::Sandbox::event(){

};