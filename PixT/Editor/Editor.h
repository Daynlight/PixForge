#pragma once
#include "../Core/Window.h"
#include "../Core/Renderer.h"
#include "../Game/Game.h"
#include "Settings.h"
#include "Tools.h"
#include "Gui.h"

namespace PE{
  class Editor{
    private:
      PC::Window window = PC::Window("PixEditor");
      Gui gui = Gui(&window);
      PG::Game game = PG::Game(&window);
      void editorEvent();
    public:
      Editor();
      ~Editor();
      void run();
  };
};