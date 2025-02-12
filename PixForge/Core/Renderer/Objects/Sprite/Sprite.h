#pragma once
#include "Window/Window.h"
#include "STL/Vector/Vector.h"
#include "STL/Math/Vec.h"
#include "STL/Math/Mat.h"

#include "Renderer/Objects/Object.h"
#include "Renderer/Texture.h"
#include "Renderer/Assets.h"

namespace PF::Core::Renderer::Objects {
class Sprite : public iObject {
private:
  std::string name = "Sprite";
  STL::Vec<int, 4> position = {0,0,0,0,0};
  int zIndex = 0;
  STL::Mat<float, 4, 4> transform = {
    1,0,0,0,
    0,1,0,0,
    0,0,1,0,
    0,0,0,1
  };
  unsigned int texture_index = 0;
  Texture* textures = nullptr;
public:
  Sprite(Texture* textures, const STL::Vec<int, 4> &position, const unsigned int &texture_index);
  Sprite(Texture* textures, const STL::Vector<std::string> &record);
public:
  const std::string save() const override;
  void load(const STL::Vector<std::string> &record) override;
  void render(const Window *window) const override;
public:
  const Type getType() const override { return Type::SPRITE; };
  std::string &getRefName() override { return name; };
  STL::Vec<int, 4> &getRefPosition() override { return position; };
  STL::Mat<float, 4, 4> &getRefTransform() { return transform; };
  int &getRefZIndex() override { return zIndex; };
  unsigned int &getRefTextureIndex() { return texture_index; };
};
}; // namespace PF::Core::Renderer::Objects