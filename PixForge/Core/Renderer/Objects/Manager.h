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
public:
  Window* window;
  STL::Vector<iObject*> objects;
  STL::File file;
public:
  Manager(const std::string &path, Window *window) : file(path), window(window) {};
  ~Manager() { for(unsigned int i = 0; i < objects.size(); i++) delete objects[i]; };
public:
  const void addColourBox(const STL::Vec<int, 4> &position, const STL::Vec<char, 4> &colour) { objects.push(new ColourBox(position, colour)); };
  const void addSprite(const STL::Vec<int, 4> &position, const unsigned int &texture_index) { objects.push(new Sprite(position, texture_index)); };
public:
  const void load();
  const void save();
};
}; // namespace PF::Core::Renderer::Objects