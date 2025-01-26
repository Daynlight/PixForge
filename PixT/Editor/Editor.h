#pragma once
#include "../vendor/data/Data.h"
#include "../Core/Window.h"
#include "../Core/Renderer.h"
#include "Settings.h"
#include "Tools.h"
#include "Gui.h"

namespace PE{
  class Editor{
    private:
      PC::Window window = PC::Window("PixEditor");
      Gui gui = Gui(&window);
      void editorEvent();
    public:
      void run();
  };
};