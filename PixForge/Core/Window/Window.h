#pragma once
#include <stdexcept>
#include "STL/File.h"
#include "STL/Folder.h"

#include "SDL2/SDL.h"
#include "imgui.h"

// Default Window Settings
#define WINDOW_SIZES 800, 600 
#define WINDOW_POSITION SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
#define WINDOW_FLAGS SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE

namespace PF{
class Window{
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
private:
  File window_settings = File("settings/window_settings.ini");
  bool running = true;
private:
  inline void changeFullScreenDesktop();
  inline void createWindow(const char* title);
  inline void createRenderer();
  inline void saveWindowSettings();
  inline void loadWindowSettings();
public:
  Window(const char* title);
  ~Window();
  void windowEvent(const SDL_Event event);
  SDL_Rect getWindowSizesAndPosition();
public:
  SDL_Renderer* getRenderer() { return renderer; };
  SDL_Window* getWindow() { return window; };
  bool isRunning() { return running; };
}; 
}; // namespace PF