#pragma once
#include "Engine/Engine.h"
#include "Renderer/Renderer.h"
#include "Gui/Gui.h"
#include "Debug/Log.h"
#include "Utilities/Folder/Folder.h"

namespace PF::FORGE{
class Forge{
private:
  PF::Utilities::Benchmark::Allocs *allocs; 
  
  ENGINE::Engine engine;
  FORGE::Renderer* renderer;
  FORGE::Gui* gui;

  UTILITIES::File window_settings = UTILITIES::File("settings/window.ini");
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF::Forge