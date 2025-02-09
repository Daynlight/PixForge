#include "ColourBox.h"

PF::Core::Renderer::Objects::ColourBox::ColourBox(const PF::STL::Vec<int, 4> &position, const PF::STL::Vec<char, 4> &colour) : colour(colour) {
  for(unsigned int i = 0; i < 4; i++) this->position[i] = position[i];
};

const char* PF::Core::Renderer::Objects::ColourBox::save() const {
  // [NOTE] This is temporary solution to time that i rework STL
  STL::Vector<std::string> record;
  record.push(STL::Convert::UintChar(getType()));
  for(unsigned int i = 0; i < 4; i++) record.push(STL::Convert::IntChar(position[i]));
  for(unsigned int i = 0; i < 4; i++) record.push(&STL::Convert::UintChar(static_cast<uint8_t>(colour[i]))[0]);
  record.push(name);
  const char* record_string = record.concat(';').c_str();
  return record_string;
};

const void PF::Core::Renderer::Objects::ColourBox::load(const STL::Vector<const char*> &record){
  for(unsigned int i = 0; i < 4; i++) position[i] = STL::Convert::CharInt(record[i + 1]);
  for(unsigned int i = 0; i < 4; i++) colour[i] = static_cast<char>(STL::Convert::CharUint(record[i + 5]));
  name = record[9];
};

const void PF::Core::Renderer::Objects::ColourBox::render(const Window *window) const {
  SDL_SetRenderDrawColor(window->getRenderer(), colour[0], colour[1], colour[2], colour[3]);
  SDL_Rect tempRect = {position[0], position[1], position[2], position[3]};
  SDL_RenderFillRect(window->getRenderer(), &tempRect);
};