#include "Assets.h"

PF::Core::Renderer::Assets* PF::Core::Renderer::Assets::instance = nullptr;

void PF::Core::Renderer::Assets::init(Window* window) { if(!instance) instance = new Assets(window); }

void PF::Core::Renderer::Assets::dealloc() { delete instance; };

PF::Core::Renderer::Assets::~Assets() { 
  if(null_texture) SDL_DestroyTexture(null_texture); 
};

SDL_Texture *PF::Core::Renderer::Assets::getNullTexture(){
  if(!get().null_texture){
    unsigned int pixels[4] = {0xFFF000F0, 0xFF000000, 0xFF000000, 0xFFF000F0};
    SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(&pixels, 2, 2, 32, 8, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
    get().null_texture = SDL_CreateTextureFromSurface(get().window->getRenderer(), surface);
    SDL_FreeSurface(surface);
  }
  return get().null_texture;
};

void PF::Core::Renderer::Assets::background(const unsigned char &r, const unsigned char &g, const unsigned char &b, const unsigned char &a) {
  SDL_SetRenderDrawColor(get().window->getRenderer(), r, g, b, a); 
  SDL_RenderClear(get().window->getRenderer());
};

void PF::Core::Renderer::Assets::background(const SDL_Colour &colour) { get().background(colour.r, colour.g, colour.b, colour.a); };