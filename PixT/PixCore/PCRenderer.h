#pragma once
#include "PCWindow.h"

namespace PC{
  namespace Renderer{
    inline void background(Window* window, SDL_Colour colour) {
      SDL_SetRenderDrawColor(window->getRenderer(), colour.r, colour.g, colour.b, colour.a); 
      SDL_RenderClear(window->getRenderer());
      };
  }
}