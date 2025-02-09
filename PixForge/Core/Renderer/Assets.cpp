#include "Assets.h"

PF::Core::Renderer::Assets* PF::Core::Renderer::Assets::assets = nullptr;

SDL_Texture *PF::Core::Renderer::Assets::getNullTexture(){
  if(!null_texture){
    unsigned int pixels[4] = {0xFFF000F0, 0xFF000000, 0xFF000000, 0xFFF000F0};
    SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(&pixels, 2, 2, 32, 8, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
    null_texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
  }
  return null_texture;
};

