#pragma once
#include <stdexcept>
#include <string>
#include "STL/File/File.h"

#include "SDL2/SDL.h"

// Default Window Settings
#define WINDOW_SIZES 800, 600 
#define WINDOW_POSITION SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
#define WINDOW_FLAGS SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE

namespace PF::CoreForge{
class Window{
private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  STL::File file;
  bool running = true;
  void changeFullScreenDesktop() const;
  void changeMaximized() const;
  void createWindow(const char* title);
  void createRenderer();
public:
  Window(const std::string &path, const char* title);
  ~Window();
  void windowEvent(const SDL_Event &event);
  const SDL_Rect getWindowSizesAndPosition() const;
  SDL_Renderer* getRenderer() const { return renderer; };
  SDL_Window* getWindow() const { return window; };
  const bool isRunning() const { return running; };
}; // class Window
}; // namespace PF::CoreForge