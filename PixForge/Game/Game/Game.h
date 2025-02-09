#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"

namespace PF {
class Game{
private:
  Core::Window *window;    
public:
  Game(Core::Window *window);
  void run();
  void event();
};
}; // namespace PF