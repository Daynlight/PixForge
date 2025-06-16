#pragma once
#include "CoreForge/Window/Window.h"
#include "Utilities/Log.h"

namespace PF {
class Sandbox{
private:
  CoreForge::Window *forgeWindow;
public:
  Sandbox(CoreForge::Window *window);
  ~Sandbox();
};
}; // namespace PF