#pragma once
#include "Window/Window.h"

#include "Sprite.h"
#include "ColourBox.h"

namespace PF{
class ObjectManager{
public:
  Vector<Object*> objects;
public:
  ~ObjectManager();
  void load(File *file);
  void save(File *file);
};
}; // namespace PF