#include "ColourBox.h"

PF::Core::Renderer::Objects::ColourBox::ColourBox(PF::STL::Vec<int, 4> position, PF::STL::Vec<char, 4> colour) : colour(colour) {
  for(size_t i = 0; i < 4; i++) this->position[i] = position[i];
}

void PF::Core::Renderer::Objects::ColourBox::render(Window *window) {
  SDL_SetRenderDrawColor(window->getRenderer(), colour[0], colour[1], colour[2], colour[3]);
  SDL_Rect tempRect = {position[0], position[1], position[2], position[3]};
  SDL_RenderFillRect(window->getRenderer(), &tempRect);
};

void PF::Core::Renderer::Objects::ColourBox::load(STL::Vector<std::string> record){
  for(size_t i = 0; i < 4; i++) position[i] = std::stoi(record[i + 1]);
  for(size_t i = 0; i < 4; i++) colour[i] = std::stoi(record[i + 4 + 1]);
};

const std::string PF::Core::Renderer::Objects::ColourBox::save(){
  STL::Vector<std::string> record;
  record.push(std::to_string(static_cast<int>(getType())));
  for(size_t i = 0; i < 4; i++) record.push(std::to_string(position[i]));
  for(size_t i = 0; i < 4; i++) record.push(std::to_string(colour[i]));
  std::string record_string = record.concat(';');
  return record_string;
};