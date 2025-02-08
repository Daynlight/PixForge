#include "Sprite.h"

void PF::Sprite::render(PF::Window *window){
  SDL_Rect rect = {position[0], position[1], position[2], position[3]};
  if(!texture_index >= texture->size())
    SDL_RenderCopy(window->getRenderer(), texture->operator[](texture_index), NULL, &rect);
  else
    SDL_RenderCopy(window->getRenderer(), null_texture, NULL, &rect);
}

const std::string PF::Sprite::save(){
  return "";
}

void PF::Sprite::load(const std::string &record){
}
