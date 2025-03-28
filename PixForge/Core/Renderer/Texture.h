#pragma once
#include "Window/Window.h"
#include "STL/File/File.h"
#include "STL/Vector/Vector.h"

#include "SDL2/SDL.h"
#include "../vendor/SDL2_image/SDL_image.h"

namespace PF::Core::Renderer{
class Texture{
private:
  STL::Vector<SDL_Texture*> textures;
  Window* window;
  STL::File file;
public:
  Texture(const std::string& path, Window* window) : file(path), window(window) {};
  ~Texture(){ clear(); };
public:
  inline void addTextureFromFile(const std::string &path) {
    if(!std::filesystem::exists(path)) return;
    SDL_Surface* surface = IMG_Load(path.c_str());
    SDL_Texture* texture = SDL_CreateTexture(window->getRenderer(), SDL_PIXELFORMAT_RGBA32,
      SDL_TEXTUREACCESS_TARGET, surface->w, surface->h);
    SDL_SetRenderTarget(window->getRenderer(), texture);
    SDL_UpdateTexture(texture, NULL, surface->pixels, surface->pitch);
    SDL_SetRenderTarget(window->getRenderer(), NULL);
    textures.push(texture);
    SDL_FreeSurface(surface);
    save();
  };
  inline void addTexture(SDL_Texture* texture) { textures.push(texture); };
  void save();
  void load();
public:
  SDL_Texture* operator[](unsigned int index) { return textures[index]; };
  const SDL_Texture* operator[](unsigned int index) const { return textures[index]; };
  void clear() { while(textures.size()) SDL_DestroyTexture(textures.pop()); };
  const size_t size() const { return textures.size(); };
};
}; // namespace PF::Core::Renderer