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
<<<<<<< HEAD:PixT/PixCore/PCWindow.h
    Window(const char* title = "PixEditor");
=======
    Window(const char* title = "");
    ~Window();
    void run(std::function<void(SDL_Window*, SDL_Renderer*)> function = nullptr, std::function<void(SDL_Event)> eventHandler = nullptr);
  private:
    void eventWindowHandler(std::function<void(SDL_Event)> eventHandler = nullptr);
>>>>>>> origin/dev:PixWorkshop/PixCore/PixCore.h
}; 
}