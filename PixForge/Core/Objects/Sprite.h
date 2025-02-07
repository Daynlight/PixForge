#pragma once
#include "Window/Window.h"
#include "STL/Vec.h"
#include "Object.h"

namespace PF{
class Sprite : public iObject{
private:
  SDL_Texture *texture;
  Vec<int, 2> position;
public:
  Type getType() override { return Type::SPRITE; };
  const char* getName() override { return "Sprite"; };
  const std::string save() override;
  void load(const std::string &record) override;
  void render(Window *window) override;
};
}; // namespace PF