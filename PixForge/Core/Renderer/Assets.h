#pragma once
#include "SDL2/SDL.h"

// Default Window Settings
#define WINDOW_SIZES 800, 600 
#define WINDOW_POSITION SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
#define WINDOW_FLAGS SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE

namespace PF::Core::Renderer{
class Assets{
private:
  static Assets* assets;
  SDL_Renderer *renderer;
public:
  static const void init(SDL_Renderer *renderer) { if(!assets) assets = new Assets(renderer); }
  static void dealloc() { delete assets; };
  static Assets& get() { return *assets; };
  Assets(Assets &assets) = delete;
  Assets operator=(Assets &assets) = delete;
private:
  Assets(SDL_Renderer *renderer) : renderer(renderer) {};
private:
  SDL_Texture *null_texture = nullptr;
public:
  SDL_Texture* getNullTexture();
};
}; // namespace PF::Core::Renderer