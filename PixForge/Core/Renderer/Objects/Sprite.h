#pragma once
#include "Window/Window.h"
#include "STL/Vec.h"
#include "Object.h"
#include "../Texture.h"

namespace PF{
class Sprite : public iObject{
private:
  Texture *texture;
  SDL_Texture* null_texture;
  Vec<int, 4> position = { 0, 0, 0, 0 };
  size_t texture_index = 0;
public:
  Sprite(Texture *texture, Vec<int, 4> position, size_t texture_index, SDL_Texture* null_texture) : texture(texture), position(position), texture_index(texture_index), null_texture(null_texture) {};
  Sprite(Texture* texture, Vector<std::string> record, SDL_Texture* null_texture) : texture(texture), null_texture(null_texture) { load(record); };
  Type getType() override { return Type::SPRITE; };
  const char* getName() override { return "Sprite"; };
  const std::string save() override;
  void load(Vector<std::string> record) override;
  void render(Window *window) override;
};
}; // namespace PF