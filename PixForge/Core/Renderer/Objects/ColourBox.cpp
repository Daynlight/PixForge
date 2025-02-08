#include "ColourBox.h"

PF::ColourBox::ColourBox(PF::Vec<int, 4> position, PF::Vec<char, 4> colour) : colour(colour) {
  for(size_t i = 0; i < 4; i++) this->position[i].i = position[i];
}

void PF::ColourBox::render(Window *window) {
  SDL_SetRenderDrawColor(window->getRenderer(), colour[0], colour[1], colour[2], colour[3]);
  SDL_Rect tempRect = {position[0].i, position[1].i, position[2].i, position[3].i};
  SDL_RenderFillRect(window->getRenderer(), &tempRect);
};

void PF::ColourBox::load(Vector<std::string> record){
  for(size_t i = 0; i < 4; i++) position[i].i = std::stoi(record[i + 1]);
  for(size_t i = 0; i < 4; i++) colour[i] = std::stoi(record[i + 4 + 1]);
};

const std::string PF::ColourBox::save(){
  Vector<std::string> record;
  record.push(std::to_string(static_cast<int>(getType())));
  for(size_t i = 0; i < 4; i++) record.push(std::to_string(position[i].i));
  for(size_t i = 0; i < 4; i++) record.push(std::to_string(colour[i]));
  std::string record_string = record.concat(';');
  return record_string;
};