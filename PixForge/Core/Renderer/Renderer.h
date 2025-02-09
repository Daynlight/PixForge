#pragma once
#include "Window/Window.h"

namespace PF::Core::Renderer{
inline const void background(const Window* window, const unsigned char &r, const unsigned char &g, const unsigned char &b, const unsigned char &a) {
  SDL_SetRenderDrawColor(window->getRenderer(), r, g, b, a); 
  SDL_RenderClear(window->getRenderer());
};
inline const void background(Window* window, const SDL_Colour &colour) { background(window, colour.r, colour.g, colour.b, colour.a); };
}; // namespace PF::Core::Renderer