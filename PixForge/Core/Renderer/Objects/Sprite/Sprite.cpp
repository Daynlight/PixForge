#include "Sprite.h"

PF::Core::Renderer::Objects::Sprite::Sprite(Texture *textures, const STL::Vec<int, 4> &position, const unsigned int &texture_index)
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
  record.push(std::to_string(zIndex));
  record.push(std::to_string(static_cast<int>(texture_index)));
  record.push(name);
  return record.concat(';').c_str();;
};

void PF::Core::Renderer::Objects::Sprite::load(const STL::Vector<std::string> &record) {
  position[0] = std::stoi(record[1]);
  position[1] = std::stoi(record[2]);
  position[2] = std::stoi(record[3]);
  position[3] = std::stoi(record[4]);
  zIndex = std::stoi(record[5]);
  texture_index = std::stoi(record[6]);
  name = record[7];
};

void PF::Core::Renderer::Objects::Sprite::render(const PF::Core::Window *window) const {
  STL::Vec<int, 4> position = this->position;
  position[0] -= position[2] / 2;
  position[1] -= position[3] / 2;
  position -= Assets::getRefWorldPosition();
  position *= transform;
  SDL_Rect rect = position.getRect();

  if(texture_index < textures->size()){
      SDL_SetTextureBlendMode((*textures)[texture_index], SDL_BLENDMODE_BLEND);
      SDL_RenderCopy(window->getRenderer(), (*textures)[texture_index], NULL, &rect);
    }
  else
    SDL_RenderCopy(window->getRenderer(), Assets::getNullTexture(), NULL, &rect);
};