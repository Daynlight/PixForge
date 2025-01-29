#pragma once
#include "../Window/Window.h"

namespace PF{
  namespace Renderer{
    inline void background(Window* window, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
      SDL_SetRenderDrawColor(window->getRenderer(), r, g, b, a); 
      SDL_RenderClear(window->getRenderer());
    };
    inline void background(Window* window, SDL_Colour colour) { background(window, colour.r, colour.g, colour.b, colour.a); };
  };
};