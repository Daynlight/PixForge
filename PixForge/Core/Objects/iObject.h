#pragma once
#include "Window/Window.h"

namespace PF{
  class Object{
    public:
      enum Type{
        SPRITE,
        COLOUR_BOX
      };
    public:
      virtual void render(Window *window) = 0;
      virtual Type getType() = 0;
      virtual const char* getName() = 0;
      virtual std::string save() = 0;
      virtual void load(std::string record) = 0;
  };
};