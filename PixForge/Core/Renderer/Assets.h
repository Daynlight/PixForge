#pragma once
#include "SDL2/SDL.h"

namespace PF::Core::Renderer{
class Assets{
public:
  static SDL_Texture* null_texture;
private:
  inline static void initNullTexture(SDL_Renderer* renderer);
public:
  static void init(SDL_Renderer* renderer);
};
}; // namespace PF::Core::Renderer