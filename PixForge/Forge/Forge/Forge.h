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
      Window window;
      Gui gui;
      Sandbox sandbox;
      Folder assets_folder = Folder("assets");
      Vector<std::string> assets_list;
      void events();
    public:
      Forge();
      ~Forge();
      void run();
  };
};