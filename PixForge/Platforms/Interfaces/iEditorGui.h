#pragma once
#include <functional>

namespace PF::PLATFORMS{
class ImGuiEngine{
  ENGINE::Window *window;
  public:
    ImGuiEngine(const std::string &path, ENGINE::Window* window);
    ~ImGuiEngine();
    void dock(std::function<void()> func);
    void topBar(std::function<void()> func);
    void events(SDL_Event event);
    void render(std::function<void()> func);
}; // class ImGuiEngine
}; // namespace PF::Engine