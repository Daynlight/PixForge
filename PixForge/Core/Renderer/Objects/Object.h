#pragma once
#include "Window/Window.h"
#include "STL/Math/Vec.h"
#include "STL/Vector/Vector.h"

namespace PF::Core::Renderer::Objects{
class iObject{
public:
  enum Type{
    SPRITE,
    COLOUR_BOX
  };
public:
  virtual const std::string save() const = 0;
  virtual void load(const STL::Vector<std::string> &record) = 0;
  virtual void render(const Window *window) const = 0;
public:
  virtual const Type getType() const = 0;
  virtual std::string &getRefName() = 0;
  virtual STL::Vec<int, 5> &getRefPosition() = 0;
};
}; // namespace PF::Core::Renderer::Objects