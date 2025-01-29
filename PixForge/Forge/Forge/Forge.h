#pragma once
#include "Window/Window.h"
#include "Render/Render.h"
#include "Gui/Gui.h"

#include "Tools/Tools.h"
#include "Settings.h"

#include "Sandbox.h"

namespace PF{
  class Forge{
    private:
      Window window = Window("PixEditor");
      Gui gui = Gui(&window);
      Sandbox sandbox = Sandbox(&window);
      void events();
    public:
      Forge();
      ~Forge();
      void run();
  };
};