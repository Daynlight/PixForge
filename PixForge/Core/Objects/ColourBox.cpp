#include "ColourBox.h"

PF::ColourBox::ColourBox(PF::Vec<int, 4> rect, PF::Vec<char, 4> colour) :rect(rect), colour(colour) {}

void PF::ColourBox::render(Window *window) {
  SDL_SetRenderDrawColor(window->getRenderer(), colour[0], colour[1], colour[2], colour[3]);
  SDL_Rect tempRect = {rect[0], rect[1], rect[2], rect[3]};
  SDL_RenderFillRect(window->getRenderer(), &tempRect);
};