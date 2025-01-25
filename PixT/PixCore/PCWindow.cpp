#include "PCWindow.h"

PC::Window::Window(const char* title)
  :title(title) {
  if(SDL_Init(SDL_INIT_EVERYTHING)) throw std::runtime_error("SDL Init Error");

  window = SDL_CreateWindow(title, WINDOW_POSITION, WINDOW_SIZES, WINDOW_FLAGS);
  if(!window) throw std::runtime_error("Can't create window");

  renderer = SDL_CreateRenderer(window, 0, 0);
  if(!renderer) throw std::runtime_error("Can't create renderer");
}

PC::Window::~Window(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void PC::Window::windowEvent(SDL_Event event){
  if(event.type == SDL_QUIT) running = false;
}

bool PC::Window::isRunning() { return running; }
SDL_Renderer *PC::Window::getRenderer() { return renderer; }

SDL_Window *PC::Window::getWindow(){
  return window;
}
