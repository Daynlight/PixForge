#pragma once
#include "../Settings.h"
#include "../PixCore/PixCore.h"
#include "../vendor/Data/Data.h"
#include "../vendor/ImGui/imgui.h"
#include "../vendor/ImGui/imgui_impl_sdl2.h"

namespace PC{
class Editor{
  private:
    Window *window;
    Data::BaseHash hash = Data::BaseHash("gamehashvalue");
    Data::File game = Data::File("game.bin");
  public:
    Editor(Window *window);
    ~Editor();
    void run();
};

}