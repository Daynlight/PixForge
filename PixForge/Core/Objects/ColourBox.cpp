#include "ColourBox.h"

PF::ColourBox::ColourBox(SDL_Rect rect, SDL_Color colour) :rect(rect), colour(colour) {}

void PF::ColourBox::render(Window *window) {
  SDL_SetRenderDrawColor(window->getRenderer(), colour.r, colour.g, colour.b, colour.a);
  SDL_RenderFillRect(window->getRenderer(), &rect);
};