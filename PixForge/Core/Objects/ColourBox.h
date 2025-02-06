#pragma once
#include "Window/Window.h"
#include "iObject.h"
#include "STL/Vec.h"

namespace PF{
  class ColourBox : public Object{
    private:
      Vec<int, 4> rect;
      Vec<char, 4> colour;
    public:
      ColourBox(Vec<int, 4> rect, Vec<char, 4> colour);
      void render(Window *window) override;
      Type getType() override { return Type::COLOUR_BOX; };
      const char* getName() override { return "Colour Box"; };
  };
};