#include "Sprite.h"

PF::Core::Renderer::Objects::Sprite::Sprite(Texture *textures, const STL::Vec<int, 5> &position, const unsigned int &texture_index)
  : textures(textures), position(position), texture_index(texture_index) {};

PF::Core::Renderer::Objects::Sprite::Sprite(Texture *textures, const STL::Vector<std::string> &record)
  : textures(textures) { load(record); };

const std::string PF::Core::Renderer::Objects::Sprite::save() const {
  STL::Vector<std::string> record;
  record.push(std::to_string(static_cast<int>(getType())));
  record.push(std::to_string(position[0]));
  record.push(std::to_string(position[1]));
  record.push(std::to_string(position[2]));
  record.push(std::to_string(position[3]));
  record.push(std::to_string(position[4]));
  record.push(std::to_string(static_cast<int>(texture_index)));
  record.push(name);
  return record.concat(';').c_str();;
};

void PF::Core::Renderer::Objects::Sprite::load(const STL::Vector<std::string> &record) {
  position[0] = std::stoi(record[1]);
  position[1] = std::stoi(record[2]);
  position[2] = std::stoi(record[3]);
  position[3] = std::stoi(record[4]);
  position[4] = std::stoi(record[5]);
  texture_index = std::stoi(record[6]);
  name = record[7];
};

void PF::Core::Renderer::Objects::Sprite::render(const PF::Core::Window *window) const {
  SDL_Rect rect = {position[0], position[1], position[3], position[4]};
  if(texture_index < textures->size())
    SDL_RenderCopy(window->getRenderer(), (*textures)[texture_index], NULL, &rect);
  else
    SDL_RenderCopy(window->getRenderer(), Assets::get().getNullTexture(), NULL, &rect);
};