#pragma once
#include "../Settings.h"
#include "../vendor/ImGui/imgui.h"
#include <stdexcept>
#include <functional>
#include <SDL2/SDL.h>

namespace PC {
class Window{
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    const char* title = "";
    bool running = true;
  public:
    Window(const char* title);
    ~Window();
    bool isRunning();
    SDL_Renderer* getRenderer();
    void windowEvent(SDL_Event event);
}; 
}