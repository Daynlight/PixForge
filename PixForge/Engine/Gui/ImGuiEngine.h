#pragma once
#include <functional>
#include "Engine/Window/Window.h"

#include "Vendor/include/imgui/imgui.h"
#include "Vendor/include/imgui/imgui_impl_sdl2.h"
#include "Vendor/include/imgui/imgui_impl_sdlrenderer2.h"

namespace PF::Engine{
class ImGuiEngine{
  CoreForge::Window *window;
  public:
    ImGuiEngine(const std::string &path, CoreForge::Window* window);
    ~ImGuiEngine();
    void dock(std::function<void()> func);
    void topBar(std::function<void()> func);
    void events(SDL_Event event);
    void render(std::function<void()> func);
}; // class ImGuiEngine
}; // namespace PF::Engine