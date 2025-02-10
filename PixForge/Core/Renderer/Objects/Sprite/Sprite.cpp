#include "Sprite.h"

const std::string PF::Core::Renderer::Objects::Sprite::save() const {
  STL::Vector<std::string> record;
  record.push(STL::Convert::UintChar(getType()));
  record.push(STL::Convert::IntChar(position[0]));
  record.push(STL::Convert::IntChar(position[1]));
  record.push(STL::Convert::IntChar(position[2]));
  record.push(STL::Convert::IntChar(position[3]));
  record.push(STL::Convert::UintChar(texture_index));
  record.push(name);
  return record.concat(';').c_str();;
};

const void PF::Core::Renderer::Objects::Sprite::load(const STL::Vector<std::string> &record){
  position[0] = std::stoi(record[1]);
  position[1] = std::stoi(record[2]);
  position[2] = std::stoi(record[3]);
  position[3] = std::stoi(record[4]);
  texture_index = std::stoi(record[5]);
  name = record[6];
};

const void PF::Core::Renderer::Objects::Sprite::render(const PF::Core::Window *window) const {
  SDL_Rect rect = {position[0], position[1], position[2], position[3]};
  if(texture_index < textures->size())
    SDL_RenderCopy(window->getRenderer(), (*textures)[texture_index], NULL, &rect);
  else
    SDL_RenderCopy(window->getRenderer(), Assets::get().getNullTexture(), NULL, &rect);
};