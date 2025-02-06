#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "Objects/Object.h"
#include "Gui/Gui.h"
#include "Gui/Ui/Ui.h"

#include "Tools/Log.h"
#include "Settings.h"

#include "Sandbox.h"

namespace PF{
  class Forge{
    private:
      Window window;
      Sandbox sandbox;
      UIManager ui;
      ObjectManager objects;
      Gui gui;
    private:
      File objects_file = File("objects.bin");
      File gui_window = File("settings/gui_window.ini");
      Folder texture_folder = Folder("assets/texture/");
    private:
      inline void events();
    public:
      Forge();
      ~Forge();
      void run();
  };
};