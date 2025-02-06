#include "Sprite.h"

void PF::Sprite::render(PF::Window *window){
  SDL_Rect dest = position.getRect();
  SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
  SDL_RenderCopy(window->getRenderer(), texture, NULL, &dest);
}