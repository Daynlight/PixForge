#pragma once
#include "Window/Window.h"
#include "Object.h"
#include "STL/Vec.h"

namespace PF{
class ColourBox : public iObject{
private:
  union IntChar{
    int i;
    char c[4];
  };
private:
  Vec<IntChar, 4> position;
  Vec<char, 4> colour = {0,0,0,0};
public:
  ColourBox(Vec<int, 4> position, Vec<char, 4> colour);
  ColourBox(std::string record) { load(record); };
public:
  const char* getName() override { return "Colour Box"; };
  Type getType() override { return Type::COLOUR_BOX; };
  const std::string save() override;
  void load(const std::string &record) override;
  void render(Window *window) override;
public:
  void setPosition(Vec<int, 4> position){ for(size_t i = 0; i < 4; i++) this->position[i].i = position[i]; };
  void setColour(Vec<char, 4> colour){ this->colour = colour; };
  Vec<char, 4> getColour(){ return { colour[0], colour[1], colour[2], colour[3] }; };
  Vec<int, 4> getPosition(){ return { position[0].i, position[1].i, position[2].i, position[3].i }; };
};
}; // namespace PF