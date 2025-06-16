// #include "Game.h"

// PF::Game::Game(Core::Window* window) :window(window){
//   Core::Renderer::Objects::Manager::load();
// };

// void PF::Game::run(){
//   while (window->isRunning()){
//     Core::Renderer::Assets::background(backgroundColour);
//     for(size_t i = 0; i < PF::Core::Renderer::Objects::Manager::size(); i++) Core::Renderer::Objects::Manager::at(i).render(window);

//     event();
//     SDL_RenderPresent(window->getRenderer());
//   };
// };

// void PF::Game::event(){
//   SDL_Event event;
//   while(SDL_PollEvent(&event)){

//     window->windowEvent(event);
//   };
// };