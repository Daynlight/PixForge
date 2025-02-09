#include "Sprite.h"

const char* PF::Core::Renderer::Objects::Sprite::save() const {
  // [NOTE] This is temporary solution to time that i rework STL
  STL::Vector<std::string> record;
  record.push(STL::Convert::UintChar(getType()));
  record.push(STL::Convert::IntChar(position[0]));
  record.push(STL::Convert::IntChar(position[1]));
  record.push(STL::Convert::IntChar(position[2]));
  record.push(STL::Convert::IntChar(position[3]));
  record.push(STL::Convert::UintChar(texture_index));
  record.push(name);
  std::string record_string = record.concat(';').c_str();
  const char* record_string_c = record_string.c_str();
  return record_string_c;
};

const void PF::Core::Renderer::Objects::Sprite::load(const STL::Vector<const char*> &record){
  position[0] = STL::Convert::CharInt(record[1]);
  position[1] = STL::Convert::CharInt(record[2]);
  position[2] = STL::Convert::CharInt(record[3]);
  position[3] = STL::Convert::CharInt(record[4]);
  texture_index = STL::Convert::CharUint(record[5]);
  name = record[6];
};

const void PF::Core::Renderer::Objects::Sprite::render(const PF::Core::Window *window) const {
  SDL_Rect rect = {position[0], position[1], position[2], position[3]};
  if(texture_index < Texture::texture->size())
    SDL_RenderCopy(window->getRenderer(), Texture::texture->operator[](texture_index), NULL, &rect);
  else
    SDL_RenderCopy(window->getRenderer(), Assets::null_texture, NULL, &rect);
};