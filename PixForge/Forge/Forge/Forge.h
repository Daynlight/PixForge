#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Gui/Gui.h"

#include "Tools/Log.h"
#include "Settings.h"

#include "Sandbox.h"

namespace PF{
  class Forge{
    private:
      Window window;
      Sandbox sandbox;
      UIManager ui;
      Gui gui;
    private:
      File gui_window = File("settings/gui_window.ini");
      Folder assets_folder = Folder("assets/");
      Folder texture_folder = assets_folder.openFolder("texture/");
    private:
      inline void loadGuiWindow();
      inline void saveGuiWindow();
      inline void events();
    public:
      Forge();
      ~Forge();
      void run();
  };
};