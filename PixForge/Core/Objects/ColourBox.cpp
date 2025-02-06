#include "ColourBox.h"

PF::ColourBox::ColourBox(PF::Vec<int, 4> position, PF::Vec<char, 4> colour) : colour(colour) {
  for(size_t i = 0; i < 4; i++) this->position[i].i = position[i];
}

void PF::ColourBox::render(Window *window) {
  SDL_SetRenderDrawColor(window->getRenderer(), colour[0], colour[1], colour[2], colour[3]);
  SDL_Rect tempRect = {position[0].i, position[1].i, position[2].i, position[3].i};
  SDL_RenderFillRect(window->getRenderer(), &tempRect);
}

void PF::ColourBox::load(std::string record){
  for(size_t i = 0; i < 4; i++)
    for(size_t j = 0; j < 4; j++)
      position[i].c[j] = record[i*4+j+1];

  for(size_t i = 0; i < 4; i++) colour[i] = record[4*4 + 1 + i];
};

std::string PF::ColourBox::save(){
  std::string record = "";
  record += (char)getType();
  for(size_t i = 0; i < 4; i++) 
    for(size_t j = 0; j < 4; j++)
      record += position[i].c[j];
  for(size_t i = 0; i < 4; i++) record += colour[i];
  return record;
};