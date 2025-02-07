#pragma once
#include "Window/Window.h"
#include "STL/File.h"

#include "Sprite.h"
#include "ColourBox.h"

namespace PF{
class ObjectManager{
public:
  Vector<iObject*> objects;
  File file;
public:
  ObjectManager(const std::string &path) : file(path) {};
  ~ObjectManager() { for(size_t i = 0; i < objects.size(); i++) delete objects[i]; };
  void load();
  void save();
};
}; // namespace PF