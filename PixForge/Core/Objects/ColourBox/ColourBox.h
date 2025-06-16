#pragma once
#include "Assets/Assets.h"
#include "STL/Vector/Vector.h"
#include "STL/Math/Vec.h"
#include "STL/Math/Mat.h"

#include "../Object.h"

namespace PF::Core::Renderer::Objects{
class ColourBox : public iObject{
private:
  std::string name = "Colour Box";
  STL::Vec<int, 4> position = {0,0,0,0};
  int zIndex = 0;
  STL::Mat<float, 4, 4> transform = {
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
  };
  STL::Vec<char, 4> colour = {0,0,0,0};
public:
  ColourBox(const STL::Vec<int, 4> &position, const STL::Vec<char, 4> &colour);
  ColourBox(const STL::Vector<std::string> &record);
public:
  const std::string save() const override;
  void load(const STL::Vector<std::string> &record) override;
  void render(const Window *window) const override;
public:
  const Type getType() const override { return Type::COLOUR_BOX; };
  std::string &getRefName() override { return name; };
  STL::Vec<int, 4> &getRefPosition() override { return position; };
  STL::Mat<float, 4, 4> &getRefTransform() { return transform; };
  int &getRefZIndex() override { return zIndex; };
  STL::Vec<char, 4> &getRefColour() { return colour; };
};
}; // namespace PF::Core::Renderer::Objects