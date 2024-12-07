#include "PixCore.h"

#ifdef SDL2
PC::Window::Window(const char* title)
  :title(title) {
  if(SDL_Init(SDL_INIT_EVERYTHING)) throw std::runtime_error("SDL Init Error");

  window = SDL_CreateWindow(title, 50, 50, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if(!window) throw std::runtime_error("Can't create window");

  renderer = SDL_CreateRenderer(window, 0, 0);
  if(!renderer) throw std::runtime_error("Can't create renderer");
}

PC::Window::~Window(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void PC::Window::run(std::function<void(SDL_Window*, SDL_Renderer*)> function, std::function<void(SDL_Event)> eventHandler){
  while(running){
    SDL_SetRenderDrawColor(renderer, WINDOWBACKGROUNDCOLOR);
    SDL_RenderClear(renderer);

    if(function) function(window, renderer);

    SDL_RenderPresent(renderer);
    eventWindowHandler(eventHandler);
  }
}

void PC::Window::eventWindowHandler(std::function<void(SDL_Event)> eventHandler) {
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(eventHandler) eventHandler(event);
    if(event.type == SDL_QUIT) running = false;
  }
}
#endif