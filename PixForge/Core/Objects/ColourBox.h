#pragma once
#include "Window/Window.h"
#include "iObject.h"
#include "STL/Vec.h"

namespace PF{
  class ColourBox : public Object{
    private:
      Vec<int, 4> position = {0,0,0,0};
      Vec<char, 4> colour = {0,0,0,0};
    public:
      ColourBox(){};
      ColourBox(Vec<int, 4> position, Vec<char, 4> colour);
      ColourBox(std::string record) { load(record); };
      void render(Window *window) override;
      Type getType() override { return Type::COLOUR_BOX; };
      const char* getName() override { return "Colour Box"; };
      std::string save() override;
      void load(std::string record) override;
  };
};