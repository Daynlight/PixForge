#pragma once
#include "Window/Window.h"
#include "Object.h"

namespace PF{
  class ColourBox : public Object{
    private:
      SDL_Rect rect;
      SDL_Color colour;
    public:
      ColourBox(SDL_Rect rect, SDL_Color colour);
      void render(Window *window) override;
  };
};