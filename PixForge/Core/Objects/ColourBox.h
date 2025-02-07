#pragma once
#include "Window/Window.h"
#include "iObject.h"
#include "STL/Vec.h"

namespace PF{
class ColourBox : public Object{
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
};
}; // namespace PF