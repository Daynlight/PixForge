#include "ColourBox.h"

PF::Core::Renderer::Objects::ColourBox::ColourBox(const PF::STL::Vec<int, 4> &position, const PF::STL::Vec<char, 4> &colour) 
  : colour(colour), position(position) {};

PF::Core::Renderer::Objects::ColourBox::ColourBox(const STL::Vector<std::string> &record) { load(record); };

const std::string PF::Core::Renderer::Objects::ColourBox::save() const {
  STL::Vector<std::string> record;
  record.push(std::to_string(static_cast<int>(getType())));
  for(unsigned int i = 0; i < 4; i++) record.push(std::to_string(position[i]));
  record.push(std::to_string(zIndex));
  for(unsigned int i = 0; i < 4; i++) record.push(std::to_string(static_cast<int>(colour[i])));
  record.push(name);
  return record.concat(';');
};

void PF::Core::Renderer::Objects::ColourBox::load(const STL::Vector<std::string> &record){
  for(unsigned int i = 0; i < 4; i++) position[i] = std::stoi(record[i + 1]);
  zIndex = std::stoi(record[5]);
  for(unsigned int i = 0; i < 4; i++) colour[i] = static_cast<char>(std::stoul(record[i + 6]));
  name = record[10];
};

void PF::Core::Renderer::Objects::ColourBox::render(const Window *window) const {
  SDL_SetRenderDrawColor(window->getRenderer(), colour[0], colour[1], colour[2], colour[3]);
  STL::Vec<int, 4> position = this->position;
  position[0] -= position[3] / 2;
  position[1] -= position[4] / 2;
  position -= Assets::getRefWorldPosition();
  position *= transform;
  SDL_Rect rect = position.getRect();
  SDL_RenderFillRect(window->getRenderer(), &rect);
};