#pragma once
#include "Window/Window.h"
#include "Renderer/Renderer.h"
#include "../vendor/SDL2_image/SDL_image.h"

#include "Gui/Gui.h"
#include "Sandbox.h"
#include "Renderer/Objects/ObjectManager.h"
#include "Renderer/Texture.h"

#include "Tools/Log.h"
#include "Settings.h"

namespace PF{
class Forge{
private:
  Window window;
  Sandbox sandbox;
  Gui gui;
  ObjectManager objects;
  Texture textures;
private:
  inline void events();
public:
  Forge();
  ~Forge();
  void run();
};
}; // namespace PF