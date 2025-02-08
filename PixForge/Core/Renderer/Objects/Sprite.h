#pragma once
#include "Window/Window.h"
#include "STL/Vec.h"
#include "Object.h"
#include "../Texture.h"

namespace PF{
class Sprite : public iObject{
private:
  Texture *texture;
  Vec<int, 4> position = { 0, 0, 0, 0 };
  size_t texture_index = 0;
public:
  Sprite(Texture *texture, Vec<int, 4> position, size_t texture_index) : texture(texture), position(position), texture_index(texture_index) {};
  Type getType() override { return Type::SPRITE; };
  const char* getName() override { return "Sprite"; };
  const std::string save() override;
  void load(const std::string &record) override;
  void render(Window *window) override;
};
}; // namespace PF