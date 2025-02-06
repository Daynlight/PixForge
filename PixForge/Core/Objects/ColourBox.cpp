#include "ColourBox.h"

PF::ColourBox::ColourBox(PF::Vec<int, 4> position, PF::Vec<char, 4> colour) :position(position), colour(colour) {}

void PF::ColourBox::render(Window *window) {
  SDL_SetRenderDrawColor(window->getRenderer(), colour[0], colour[1], colour[2], colour[3]);
  SDL_Rect tempRect = {position[0], position[1], position[2], position[3]};
  SDL_RenderFillRect(window->getRenderer(), &tempRect);
}

void PF::ColourBox::load(std::string record){
  Vector<std::string> data;
  for(size_t i = 0; i < record.size(); i++){
    if(record[i] == ';'){
      data.push(record.substr(0, i));
      record = record.substr(i + 1);
      i = 0;
    };
  };

  for(size_t i = 0; i < 4; i++) position[i] = std::stoi(data[i + 1]);
  for(size_t i = 0; i < 4; i++) colour[i] = data[5][i];
};

std::string PF::ColourBox::save(){
  std::string record = "";
  record += (char)getType();
  record += ";";
  for(size_t i = 0; i < 4; i++) record += std::to_string(position[i]) + ";";
  for(size_t i = 0; i < 4; i++) record += colour[i];
  record += ";";
  return record;
};