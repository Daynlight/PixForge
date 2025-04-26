#pragma once
#include <SDL2/SDL.h>

namespace Renderer
{
class SDLRenderer
{
private:
  SDL_Window* window;
  SDL_Renderer* renderer;
  int width;
  int height;
public:
  SDLRenderer(const char* title, int width, int height);
  ~SDLRenderer();
  void clear();
  void present();
  void drawRect(int x, int y, int w, int h);
  void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  bool isRunning();
}; // class SDLRenderer
}; // namespace Renderer