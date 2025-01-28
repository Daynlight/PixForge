#pragma once
#include "../../Core/Window/Window.h"
#include "../../Core/Render/Render.h"
#include "../../Game/Sandbox/Sandbox.h"
#include "../Settings.h"
#include "../Tools/Tools.h"
#include "../Gui/Gui.h"

namespace PE{
  class Forge{
    private:
      PC::Window window = PC::Window("PixEditor");
      Gui gui = Gui(&window);
      PG::Sandbox sandbox = PG::Sandbox(&window);
      void events();
    public:
      Forge();
      ~Forge();
      void run();
  };
};