#pragma once
#include "Window/Window.h"

namespace PF{
class iObject{
public:
  enum Type{
    SPRITE,
    COLOUR_BOX
  };
public:
  virtual const char* getName() = 0;
  virtual Type getType() = 0;
  virtual const std::string save() = 0;
  virtual void load(const std::string &record) = 0;
  virtual void render(Window *window) = 0;
};
}; // namespace PF