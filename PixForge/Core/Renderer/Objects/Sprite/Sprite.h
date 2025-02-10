#pragma once
#include "Window/Window.h"
#include "STL/Vec/Vec.h"
#include "STL/Vector/Vector.h"

#include "Renderer/Objects/Object.h"
#include "Renderer/Texture.h"
#include "Renderer/Assets.h"

namespace PF::Core::Renderer::Objects{
class Sprite : public iObject{
private:
  std::string name = "Sprite";
  STL::Vec<int, 4> position = {0, 0, 0, 0};
private:
  unsigned int texture_index = 0;
  Texture* textures = nullptr;
public:
  Sprite(Texture* textures, STL::Vec<int, 4> position, unsigned int texture_index) : textures(textures), position(position), texture_index(texture_index) {};
  Sprite(Texture* textures, const STL::Vector<std::string> &record) : textures(textures) { load(record); };
public:
  const std::string save() const override;
  const void load(const STL::Vector<std::string> &record) override;
  const void render(const Window *window) const override;
public:
  const Type getType() const override { return Type::SPRITE; };
  const std::string getName() const override { return name; };
  const void setName(const std::string &name) override { this->name = name; };
  const STL::Vec<int, 4> getPosition() const override { return { position[0], position[1], position[2], position[3] }; };
  const void setPosition(const STL::Vec<int, 4> &position) { this->position = position; };
public:
  const unsigned int getTextureIndex() const { return texture_index; };
  const void setTextureIndex(unsigned int texture_index) { this->texture_index = texture_index; };
};
}; // namespace PF::Core::Renderer::Objects