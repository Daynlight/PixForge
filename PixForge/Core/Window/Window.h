#pragma once
#include <stdexcept>

#include "../STL/STL.h"

#include "SDL2/SDL.h"
#include "../../vendor/imgui/imgui.h"

// Default Window Settings
#define WINDOW_SIZES 800, 600 
#define WINDOW_POSITION SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
#define WINDOW_FLAGS SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE

namespace PF {
class Window{
  private:
    File window_settings = File("settings/window_settings.ini");
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running = true;
    inline void changeFullScreenDesktop();
    inline void createWindow(const char* title);
    inline void createRenderer();
  public:
    Window(const char* title);
    ~Window();
    bool isRunning();
    void windowEvent(const SDL_Event event);
    SDL_Renderer* getRenderer();
    SDL_Window* getWindow();
    SDL_Rect getWindowSizesAndPosition();
  }; 
};