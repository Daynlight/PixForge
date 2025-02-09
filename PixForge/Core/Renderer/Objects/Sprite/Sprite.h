#pragma once
#include "Window/Window.h"
#include "STL/Vec/Vec.h"
#include "STL/Vector/Vector.h"

#include "STL/Convert/IntChar.h"
#include "STL/Convert/CharInt.h"
#include "STL/Convert/UintChar.h"
#include "STL/Convert/CharUint.h"

#include "Renderer/Objects/Object.h"
#include "Renderer/Texture.h"
#include "Renderer/Assets.h"

namespace PF::Core::Renderer::Objects{
class Sprite : public iObject{
private:
  const char* name = "Sprite";
  STL::Vec<int, 4> position = {0, 0, 0, 0};
private:
  unsigned int texture_index = 0;
public:
  Sprite(STL::Vec<int, 4> position, unsigned int texture_index) : position(position), texture_index(texture_index) {};
  Sprite(const STL::Vector<const char*> &record) { load(record); };
public:
  const char* save() const override;
  const void load(const STL::Vector<const char*> &record) override;
  const void render(const Window *window) const override;
public:
  const Type getType() const override { return Type::SPRITE; };
  const char* getName() const override { return name; };
  const void setName(const char* name) override { this->name = name; };
  const STL::Vec<int, 4> getPosition() const override { return { position[0], position[1], position[2], position[3] }; };
  const void setPosition(const STL::Vec<int, 4> &position) { this->position = position; };
public:
  const unsigned int getTextureIndex() const { return texture_index; };
  const void setTextureIndex(unsigned int texture_index) { this->texture_index = texture_index; };
};
}; // namespace PF::Core::Renderer::Objects