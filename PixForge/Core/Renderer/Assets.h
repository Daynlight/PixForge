#pragma once
#include "SDL2/SDL.h"
#include "Window/Window.h"

#define backgroundColour 25,25,25,255

namespace PF::Core::Renderer{
class Assets{
private:
  static Assets* instance;
  Window *window;
public:
  static Assets& get() { return *instance; };
  static void init(Window* window);
  static void dealloc();
  Assets(Assets &assets) = delete;
  Assets operator=(Assets &assets) = delete;
private:
  Assets(Window *window) : window(window) {};
  ~Assets();
private:
  SDL_Texture *null_texture = nullptr;
public:
  static SDL_Texture* getNullTexture();
  static void background(const SDL_Colour &colour);
  static void background(const unsigned char &r, const unsigned char &g, const unsigned char &b, const unsigned char &a);
};
}; // namespace PF::Core::Renderer