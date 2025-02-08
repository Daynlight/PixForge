#pragma once
#include "Window/Window.h"
#include "STL/File.h"
#include "../Texture.h"

#include "Sprite.h"
#include "ColourBox.h"

namespace PF{
class ObjectManager{
public:
  Vector<iObject*> objects;
  Texture* texture;
  File file;
public:
  ObjectManager(const std::string &path, Texture *texture) : file(path), texture(texture) {};
  ~ObjectManager() { for(size_t i = 0; i < objects.size(); i++) delete objects[i]; };
  void add(iObject* object) { objects.push(object); };
  void load();
  void save();
};
}; // namespace PF