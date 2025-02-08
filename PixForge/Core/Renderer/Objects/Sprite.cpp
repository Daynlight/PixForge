#include "Sprite.h"

void PF::Sprite::render(PF::Window *window){
  SDL_Rect rect = {position[0], position[1], position[2], position[3]};
  if(!texture_index >= texture->size())
    SDL_RenderCopy(window->getRenderer(), texture->operator[](texture_index), NULL, &rect);
  else
    SDL_RenderCopy(window->getRenderer(), null_texture, NULL, &rect);
}

const std::string PF::Sprite::save(){
  Vector<std::string> record;
  record.push(std::to_string(static_cast<int>(getType())));
  record.push(std::to_string(position[0]));
  record.push(std::to_string(position[1]));
  record.push(std::to_string(position[2]));
  record.push(std::to_string(position[3]));
  record.push(std::to_string(texture_index));
  std::string record_string = record.concat(';');
  return record_string;
}

void PF::Sprite::load(Vector<std::string> record){
  position[0] = std::stoi(record[1]);
  position[1] = std::stoi(record[2]);
  position[2] = std::stoi(record[3]);
  position[3] = std::stoi(record[4]);
  texture_index = std::stoi(record[5]);
};
