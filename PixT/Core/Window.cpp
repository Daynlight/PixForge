#include "Window.h"

PC::Window::Window(const char* title)
  :title(title) {
  if(SDL_Init(SDL_INIT_EVERYTHING)) throw std::runtime_error("SDL Init Error");

  if(window_settings.isEmpty()) {
    window_settings.createFile();
    window = SDL_CreateWindow(title, WINDOW_POSITION, WINDOW_SIZES, WINDOW_FLAGS);
    if(!window) throw std::runtime_error("Can't create window");
  }
  else{
    window_settings.read();
    window = SDL_CreateWindow(title, std::stoi(window_settings[0]), std::stoi(window_settings[1]), 
      std::stoi(window_settings[2]), std::stoi(window_settings[3]), WINDOW_FLAGS);
    if(!window) throw std::runtime_error("Can't create window");
  }

  renderer = SDL_CreateRenderer(window, 0, 0);
  if(!renderer) throw std::runtime_error("Can't create renderer");
}

PC::Window::~Window(){
  int x, y, w, h;
  SDL_GetWindowPosition(window ,&x, &y);
  SDL_GetWindowSize(window, &w, &h);
  while(window_settings.size() > 0) window_settings.pop();
  window_settings.push(std::to_string(x));
  window_settings.push(std::to_string(y));
  window_settings.push(std::to_string(w));
  window_settings.push(std::to_string(h));
  window_settings.save();

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void PC::Window::windowEvent(SDL_Event event){
  if(event.type == SDL_QUIT) running = false;
}

bool PC::Window::isRunning() { return running; }
SDL_Renderer *PC::Window::getRenderer() { return renderer; }
SDL_Window *PC::Window::getWindow() { return window; }
