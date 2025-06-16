#pragma once
#include "Core.h"

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