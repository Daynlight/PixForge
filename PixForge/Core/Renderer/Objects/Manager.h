#pragma once
#include "Window/Window.h"
#include "STL/File/File.h"
#include "../Texture.h"

#include "Renderer/Objects/Sprite/Sprite.h"
#include "Renderer/Objects/ColourBox/ColourBox.h"

namespace PF::Core::Renderer::Objects{
class Manager{
public:
  Window* window;
  STL::Vector<iObject*> objects;
  Texture* texture;
  STL::File file;
  SDL_Texture* null_texture;
public:
  Manager(const std::string &path, Texture *texture, Window *window) : file(path), texture(texture), window(window) {
    Uint32* pixels = new Uint32[4];
    pixels[0] = 0xFFF000F0;
    pixels[1] = 0xFF000000;
    pixels[2] = 0xFF000000;
    pixels[3] = 0xFFF000F0;
    SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(pixels, 2, 2, 32, 8, 0xFF, 0xFF00, 0xFF0000, 0xFF000000);
    null_texture = SDL_CreateTextureFromSurface(window->getRenderer(), surface);
    SDL_FreeSurface(surface);
    delete[] pixels;
  };
  ~Manager() { for(size_t i = 0; i < objects.size(); i++) delete objects[i]; };
  void add(iObject* object) { objects.push(object); };
  void addSprite(STL::Vec<int, 4> position, size_t texture_index) { objects.push(new Objects::Sprite(texture, position, texture_index, null_texture)); };
  void load();
  void save();
};
}; // namespace PF::Core::Renderer::Objects