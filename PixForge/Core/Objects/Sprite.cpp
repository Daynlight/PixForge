#include "Sprite.h"

void PF::Sprite::render(PF::Window *window){
  SDL_Rect dest = {position[0], position[1], 0, 0};
  SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
  SDL_RenderCopy(window->getRenderer(), texture, NULL, &dest);
}