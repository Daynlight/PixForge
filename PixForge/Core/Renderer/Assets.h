#pragma once
#include "SDL2/SDL.h"

namespace PF::Core::Renderer{
class Assets{
private:
  static Assets* assets;
  SDL_Renderer *renderer;
public: // Singleton
  static const void init(SDL_Renderer *renderer) { if(!assets) assets = new Assets(renderer); }
  static Assets& get() { return *assets; };
  Assets(Assets &assets) = delete;
  Assets operator=(Assets &assets) = delete;
private:
  Assets(SDL_Renderer *renderer) : renderer(renderer) {};
  ~Assets() { delete assets; };
private:
  SDL_Texture *null_texture = nullptr;
public:
  SDL_Texture* getNullTexture();
};
}; // namespace PF::Core::Renderer