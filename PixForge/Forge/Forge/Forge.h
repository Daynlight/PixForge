#pragma once
#include "../../Core/Window/Window.h"
#include "../../Core/Render/Render.h"
#include "../../Game/Sandbox/Sandbox.h"
#include "../Settings.h"
#include "../Tools/Tools.h"
#include "../Gui/Gui.h"

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