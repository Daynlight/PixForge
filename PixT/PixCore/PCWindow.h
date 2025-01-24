#pragma once
#include "../Settings.h"
#include "../vendor/ImGui/imgui.h"
#include <functional>
#include <stdexcept>
#include <SDL2/SDL.h>

namespace PC {
class Window{
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    const char* title = "";
    bool running = true;
  public:
    Window(const char* title = "PixEditor");
}; 
}