#pragma once
#include "Window/Window.h"
#include "STL/Vector/Vector.h"
#include "STL/Vec/Vec.h"

#include "STL/Convert/IntChar.h"
#include "STL/Convert/CharInt.h"
#include "STL/Convert/UintChar.h"
#include "STL/Convert/CharUint.h"

#include "Renderer/Objects/Object.h"

namespace PF::Core::Renderer::Objects{
class ColourBox : public iObject{
private:
  const char* name = "Colour Box";
  STL::Vec<int, 4> position = {0,0,0,0};
private:
  STL::Vec<char, 4> colour = {0,0,0,0};
public:
  ColourBox(const STL::Vec<int, 4> &position, const STL::Vec<char, 4> &colour);
  ColourBox(const STL::Vector<const char*> &record) { load(record); };
public:
  const char* save() const override;
  const void load(const STL::Vector<const char*> &record) override;
  const void render(const Window *window) const override;
public:
  const Type getType() const override { return Type::COLOUR_BOX; };
  const char* getName() const override { return name; };
  const void setName(const char* name) override { this->name = name; };
  const STL::Vec<int, 4> getPosition() const override { return { position[0], position[1], position[2], position[3] }; };
  const void setPosition(const STL::Vec<int, 4> &position) { this->position = position; };
public:
  const STL::Vec<char, 4> getColour() const { return { colour[0], colour[1], colour[2], colour[3] }; };
  const void setColour(const STL::Vec<char, 4> &colour){ this->colour = colour; };
};
}; // namespace PF::Core::Renderer::Objects