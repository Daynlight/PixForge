#pragma once
#include "../Core/Window/Window.h"
#include "../Core/Render/Render.h"
#include "../Game/Sandbox/Sandbox.h"
#include "Settings.h"
#include "Tools.h"
#include "Gui.h"

namespace PE{
  class Editor{
    private:
      PC::Window window = PC::Window("PixEditor");
      Gui gui = Gui(&window);
      PG::Sandbox sandbox = PG::Sandbox(&window);
      void editorEvent();
    public:
      Editor();
      ~Editor();
      void run();
  };
};