#pragma once
#include "Window/Window.h"
#include "STL/File/File.h"
#include "STL/Vec/Vec.h"
#include "STL/Vector/Vector.h"

#include "Renderer/Texture.h"
#include "Renderer/Assets.h"

#include "Renderer/Objects/Object.h"
#include "Renderer/Objects/Sprite/Sprite.h"
#include "Renderer/Objects/ColourBox/ColourBox.h"

namespace PF::Core::Renderer::Objects{
class Manager{
private:
  static Manager* manager;
  STL::Vector<iObject*> objects;
  Texture* textures = nullptr;
  STL::File file;
public:
  static Manager& get() { return *manager; };
  static void init(const std::string &object_path, const std::string &texture_path, Window *window);
  static void dealloc();
  Manager(Manager &manager) = delete;
  Manager operator=(Manager &manager) = delete;
private:
  Manager(const std::string &object_path);
  ~Manager();
public:
  void load();
  void save();
public:
  void addColourBox(const STL::Vec<int, 5> &position, const STL::Vec<char, 4> &colour);
  void addSprite(const STL::Vec<int, 5> &position, const unsigned int &texture_index);
public:
  void updateZIndex() { objects.sort([](iObject* a, iObject* b) { return a->getRefPosition()[2] > b->getRefPosition()[2]; }); };
  iObject &operator[](const unsigned int &index) const { return *objects[index]; };
  const size_t size() const { return objects.size(); };
  void push(iObject* object) { objects.push(object); };
  void remove(const unsigned int &index) { objects.remove(index); };
  void refreshAssets() { textures->load(); };
};
}; // namespace PF::Core::Renderer::Objects