#pragma once
#include "Window/Window.h"
#include "STL/File/File.h"
#include "STL/Math/Vec.h"
#include "STL/Vector/Vector.h"

#include "Renderer/Texture.h"
#include "Renderer/Assets.h"

#include "Renderer/Objects/Object.h"
#include "Renderer/Objects/Sprite/Sprite.h"
#include "Renderer/Objects/ColourBox/ColourBox.h"

namespace PF::Core::Renderer::Objects{
class Manager{
private:
  static Manager* instance;
  STL::Vector<iObject*> objects;
  Texture* textures = nullptr;
  STL::File file;
public:
  static Manager& get() { return *instance; };
  static void init(const std::string &object_path, const std::string &texture_path, Window *window);
  static void dealloc();
  Manager(Manager &manager) = delete;
  Manager operator=(Manager &manager) = delete;
private:
  Manager(const std::string &object_path);
  ~Manager();
public:
  static void load();
  static void save();
public:
  static void addColourBox(const STL::Vec<int, 4> &position, const STL::Vec<char, 4> &colour);
  static void addSprite(const STL::Vec<int, 4> &position, const unsigned int &texture_index);
public:
  static void updateZIndex() { get().objects.sort([](iObject* a, iObject* b) { return a->getRefZIndex() < b->getRefZIndex(); }); };
  iObject &operator[](const unsigned int &index) const { return *objects[index]; };
  static iObject &at(const unsigned int &index) { return *get().objects[index]; };
  static const size_t size() { return get().objects.size(); };
  static void push(iObject* object) { get().objects.push(object); };
  static void remove(const unsigned int &index) { get().objects.remove(index); };
  static void refreshAssets() { get().textures->load(); };
};
}; // namespace PF::Core::Renderer::Objects