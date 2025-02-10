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
  STL::File file;
  Window* window;
public:
  Texture(const std::string& path, Window* window) : file(path), window(window) {};
  ~Texture(){ clear(); };
public:
  inline const void addTextureFromFile(const std::string &path);
  inline const void addTexture(SDL_Texture* texture) { textures.push(texture); };
  const void save();
  const void load();
public:
  SDL_Texture* operator[](unsigned int index) { return textures[index]; };
  const SDL_Texture* operator[](unsigned int index) const { return textures[index]; };
  const void clear() { while(textures.size()) SDL_DestroyTexture(textures.pop()); };
  const size_t size() const { return textures.size(); };
};
}; // namespace PF::Core::Renderer