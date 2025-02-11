#include "Window.h"

PF::Core::Window::Window(const char* title) {
  STL::Folder settings = STL::Folder("settings/");
  if(!settings.exist()) settings.create();
  load();

  if(SDL_Init(SDL_INIT_EVERYTHING)) throw std::runtime_error("SDL Init Error");
  
  createWindow(title);
  createRenderer();
};

PF::Core::Window::~Window(){
  save();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
};

void PF::Core::Window::createWindow(const char *title){
  if(!window_settings.size())
  window = SDL_CreateWindow(title, WINDOW_POSITION, WINDOW_SIZES, WINDOW_FLAGS);
  else{
    window = SDL_CreateWindow(title, std::stoi(window_settings[0]), std::stoi(window_settings[1]), 
    std::stoi(window_settings[2]), std::stoi(window_settings[3]), WINDOW_FLAGS);
    if(!window) throw std::runtime_error("Can't create window");  
  };

  if(window_settings[4] == "1"){
    SDL_MaximizeWindow(window);
  };
  if(window_settings[5] == "1"){
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
  };
};

void PF::Core::Window::createRenderer(){
  renderer = SDL_CreateRenderer(window, 0, 0);
  if(!renderer) throw std::runtime_error("Can't create renderer");
};

void PF::Core::Window::save() {
  SDL_Rect window_location = getWindowSizesAndPosition();
  if(!window_settings.exist()) window_settings.create();
  window_settings.clear();

  bool maximized = false;
  if(SDL_GetWindowFlags(window) & SDL_WINDOW_MAXIMIZED) maximized = true;
  bool fullscreen = false;
  if(SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP) fullscreen = true;
  
  if(maximized || fullscreen){
    window_settings.push(std::to_string(window_location.x));
    window_settings.push(std::to_string(window_location.y));
    STL::Vec<int, 2> window_size = {WINDOW_SIZES};
    window_settings.push(std::to_string(window_size[0]));
    window_settings.push(std::to_string(window_size[1]));
  }
  else{
    window_settings.push(std::to_string(window_location.x));
    window_settings.push(std::to_string(window_location.y));
    window_settings.push(std::to_string(window_location.w));
    window_settings.push(std::to_string(window_location.h));
  };
  
  window_settings.push(std::to_string(maximized));
  window_settings.push(std::to_string(fullscreen));
  
  std::string record = window_settings.concat(';');
  window_settings.clear();
  window_settings.push(record);
  window_settings.save();
};

void PF::Core::Window::load() {
  if(window_settings.exist()) {
    window_settings.read();
    STL::Vector<std::string> *record = window_settings.split(';')[0];
    window_settings.clear();
    for(size_t i = 0; i < record->size(); i++) window_settings.push((*record)[i]);
    delete record;
  }
};

const SDL_Rect PF::Core::Window::getWindowSizesAndPosition() const {
  int x, y, w, h;
  SDL_GetWindowPosition(window ,&x, &y);
  SDL_GetWindowSize(window, &w, &h);
  return {x,y,w,h};
};

void PF::Core::Window::windowEvent(const SDL_Event &event){
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

void PF::Core::Window::changeFullScreenDesktop() const{
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

void PF::Core::Window::changeMaximized() const {
  Uint32 flags = SDL_GetWindowFlags(window);
  if(flags & SDL_WINDOW_MAXIMIZED)
    SDL_RestoreWindow(window);
  else
    SDL_MaximizeWindow(window);
  SDL_Delay(500);
};