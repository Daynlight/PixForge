#pragma once
#include "Window/Window.h"
#include "STL/File/File.h"
#include "STL/Vec/Vec.h"
#include "STL/Vector/Vector.h"

#include "STL/Convert/UintChar.h"
#include "STL/Convert/CharUint.h"

#include "Renderer/Texture.h"
#include "Renderer/Assets.h"

#include "Renderer/Objects/Object.h"
#include "Renderer/Objects/Sprite/Sprite.h"
#include "Renderer/Objects/ColourBox/ColourBox.h"

namespace PF::Core::Renderer::Objects{
class Manager{
private:
  static Manager* manager;
  Window* window;
  STL::Vector<iObject*> objects;
  Texture* textures = nullptr;
  STL::File file;
public: // Singleton
  static void init(const std::string &object_path, const std::string &texture_path, Window *window) { 
    if(!manager) {
      manager = new Manager(object_path, window); 
      manager->textures = new Texture(texture_path, window);
    };
  };
  static Manager& get() { return *manager; };
  Manager(Manager &manager) = delete;
  Manager operator=(Manager &manager) = delete;
private:
  Manager(const std::string &object_path, Window *window) : file(object_path), window(window) {};
  ~Manager() { for(unsigned int i = 0; i < objects.size(); i++) delete objects[i]; };
public:
  const void addColourBox(const STL::Vec<int, 4> &position, const STL::Vec<char, 4> &colour) { objects.push(new ColourBox(position, colour)); };
  const void addSprite(const STL::Vec<int, 4> &position, const unsigned int &texture_index) { objects.push(new Sprite(textures, position, texture_index)); };
public:
  iObject &operator[](unsigned int index) { return *objects[index]; };
  const size_t size() const { return objects.size(); };
  const void push(iObject* object) { objects.push(object); };
  const void remove(unsigned int index) { objects.remove(index); };
  const void loadAssets() { textures->load(); };
public:
  const void load();
  const void save();
};
}; // namespace PF::Core::Renderer::Objects