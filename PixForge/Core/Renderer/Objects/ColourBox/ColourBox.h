#pragma once
#include "Window/Window.h"
#include "STL/Vector/Vector.h"
#include "STL/Vec/Vec.h"

#include "Renderer/Objects/Object.h"

namespace PF::Core::Renderer::Objects{
class ColourBox : public iObject{
private:
  std::string name = "Colour Box";
  STL::Vec<int, 5> position = {0,0,0,0,0};
  STL::Vec<char, 4> colour = {0,0,0,0};
public:
  ColourBox(const STL::Vec<int, 5> &position, const STL::Vec<char, 4> &colour);
  ColourBox(const STL::Vector<std::string> &record);
public:
  const std::string save() const override;
  void load(const STL::Vector<std::string> &record) override;
  void render(const Window *window) const override;
public:
  const Type getType() const override { return Type::COLOUR_BOX; };
  std::string &getRefName() override { return name; };
  STL::Vec<int, 5> &getRefPosition() override { return position; };
  STL::Vec<char, 4> &getRefColour() { return colour; };
};
}; // namespace PF::Core::Renderer::Objects