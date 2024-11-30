#pragma once
#include "../Settings.h"
#include <stdexcept>

#ifdef SDL2
#include <SDL2/SDL.h>

namespace PC {
class DLLIO Window{
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    const char* title = "";
  public:
    Window(const char* title = "");
}; 
} // namespace PC
#elif GLFW
  #include <GLFW/glfw3.h>
#elif GLEW
  #include <GL/gl.h>
#endif

