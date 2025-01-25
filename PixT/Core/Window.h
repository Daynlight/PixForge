#pragma once
#include "../Assets/Settings.h"
#include "../vendor/imgui/imgui.h"
#include <SDL2/SDL.h>
#include <stdexcept>

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
    SDL_Window* getWindow();
    void windowEvent(SDL_Event event);
}; 
}