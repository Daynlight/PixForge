#pragma once
#include "Window/Window.h"
#include "STL/Vec/Vec.h"
#include "Renderer/Objects/Object.h"
#include "Renderer/Texture.h"

namespace PF::Core::Renderer::Objects{
class Sprite : public iObject{
private:
  Texture *texture;
  SDL_Texture* null_texture;
  STL::Vec<int, 4> position = { 0, 0, 0, 0 };
  size_t texture_index = 0;
public:
  Sprite(Texture *texture, STL::Vec<int, 4> position, size_t texture_index, SDL_Texture* null_texture) : texture(texture), position(position), texture_index(texture_index), null_texture(null_texture) {};
  Sprite(Texture* texture, STL::Vector<std::string> record, SDL_Texture* null_texture) : texture(texture), null_texture(null_texture) { load(record); };
  Type getType() override { return Type::SPRITE; };
  const char* getName() override { return "Sprite"; };
  const std::string save() override;
  void load(STL::Vector<std::string> record) override;
  void render(Window *window) override;
  void setPosition(STL::Vec<int, 4> position) { this->position = position; };
  void setTextureIndex(size_t texture_index) { this->texture_index = texture_index; };
};
}; // namespace PF::Core::Renderer::Objects