#include "PCWindow.h"

PC::Window::Window(const char* title)
  :title(title) {
  if(SDL_Init(SDL_INIT_EVERYTHING)) throw std::runtime_error("SDL Init Error");

  window = SDL_CreateWindow(title, 50, 50, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  if(!window) throw std::runtime_error("Can't create window");

  renderer = SDL_CreateRenderer(window, 0, 0);
  if(!renderer) throw std::runtime_error("Can't create renderer");
}
