#pragma once
#include "Window/Window.h"
#include "Renderer/Objects/Object.h"
#include "STL/Vec/Vec.h"

namespace PF::Core::Renderer::Objects{
class ColourBox : public iObject{
private:
private:
  STL::Vec<int, 4> position;
  STL::Vec<char, 4> colour = {0,0,0,0};
public:
  ColourBox(STL::Vec<int, 4> position, STL::Vec<char, 4> colour);
  ColourBox(STL::Vector<std::string> record) { load(record); };
public:
  const char* getName() override { return "Colour Box"; };
  Type getType() override { return Type::COLOUR_BOX; };
  const std::string save() override;
  void load(STL::Vector<std::string> record) override;
  void render(Window *window) override;
public:
  void setPosition(STL::Vec<int, 4> position){ for(size_t i = 0; i < 4; i++) this->position[i] = position[i]; };
  void setColour(STL::Vec<char, 4> colour){ this->colour = colour; };
  STL::Vec<char, 4> getColour(){ return { colour[0], colour[1], colour[2], colour[3] }; };
  STL::Vec<int, 4> getPosition(){ return { position[0], position[1], position[2], position[3] }; };
};
}; // namespace PF::Core::Renderer::Objects