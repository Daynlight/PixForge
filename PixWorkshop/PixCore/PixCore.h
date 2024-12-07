#pragma once
#include "../Settings.h"
#include <functional>
#include <stdexcept>

#ifdef SDL2
#include <SDL2/SDL.h>

namespace PC {
class DLLIO Window{
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    const char* title = "";
    bool running = true;
  public:
    Window(const char* title = "");
    ~Window();
    void run(std::function<void(SDL_Window*, SDL_Renderer*)> function = nullptr, std::function<void(SDL_Event)> eventHandler = nullptr);
  private:
    void eventWindowHandler(std::function<void(SDL_Event)> eventHandler = nullptr);
}; 
} // namespace PC
#elif GLFW
  #include <GLFW/glfw3.h>
#elif GLEW
  #include <GL/gl.h>
#endif

