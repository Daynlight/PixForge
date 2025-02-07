#pragma once
#include "iObject.h"
#include "SDL2/SDL.h"
#include "STL/Vec.h"
#include "Window/Window.h"

namespace PF{
class Sprite : public Object{
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