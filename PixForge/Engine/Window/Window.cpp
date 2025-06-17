#include "Window.h"

PF::CoreForge::Window::Window(const std::string &path, const char* title)
  : file(path) {
  if(SDL_Init(SDL_INIT_EVERYTHING)) throw std::runtime_error("SDL Init Error");
  createWindow(title);
  createRenderer();
};

PF::CoreForge::Window::~Window(){
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
};

void PF::CoreForge::Window::createWindow(const char *title){
  window = SDL_CreateWindow(title, WINDOW_POSITION, WINDOW_SIZES, WINDOW_FLAGS);
};

void PF::CoreForge::Window::createRenderer(){
  renderer = SDL_CreateRenderer(window, 0, 0);
  if(!renderer) throw std::runtime_error("Can't create renderer");
};

const SDL_Rect PF::CoreForge::Window::getWindowSizesAndPosition() const {
  int x, y, w, h;
  SDL_GetWindowPosition(window ,&x, &y);
  SDL_GetWindowSize(window, &w, &h);
  return {x,y,w,h};
};

void PF::CoreForge::Window::windowEvent(const SDL_Event &event){
  if(event.type == SDL_QUIT) running = false;
  if(event.type == SDL_KEYDOWN){
    if(event.key.keysym.sym == SDLK_F11) changeFullScreenDesktop();
    if(event.key.keysym.sym == SDLK_F10) changeMaximized();
  };
  if(event.type == SDL_WINDOWEVENT){
    if(event.window.event == SDL_WINDOWEVENT_RESTORED) SDL_SetWindowPosition(window, WINDOW_POSITION);
    if(event.window.event == SDL_WINDOW_FULLSCREEN_DESKTOP) SDL_SetWindowPosition(window, WINDOW_POSITION);
  };
};

void PF::CoreForge::Window::changeFullScreenDesktop() const{
  Uint32 flags = SDL_GetWindowFlags(window);
  if(flags & SDL_WINDOW_FULLSCREEN_DESKTOP) {
    SDL_SetWindowFullscreen(window, 0);
    SDL_MaximizeWindow(window);
    SDL_RestoreWindow(window);
  } else {
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
  }
  SDL_Delay(500);
};

void PF::CoreForge::Window::changeMaximized() const {
  Uint32 flags = SDL_GetWindowFlags(window);
  if(flags & SDL_WINDOW_MAXIMIZED)
    SDL_RestoreWindow(window);
  else
    SDL_MaximizeWindow(window);
  SDL_Delay(500);
};