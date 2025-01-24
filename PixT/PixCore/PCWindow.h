#pragma once
#include "../Settings.h"
#include <stdexcept>
#include <SDL2/SDL.h>

namespace PC {
class Window{
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    const char* title = "";
  public:
    Window(const char* title = "PixEditor");
}; 
}