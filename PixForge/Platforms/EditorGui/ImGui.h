// #pragma once
// #include <functional>
// #include "Interfaces/iRenderer.h"

// #include "Vendor/imgui-1.91.9b/imgui.h"
// #include "Vendor/imgui-1.91.9b/backends/imgui_impl_glfw.h"
// #include "Vendor/imgui-1.91.9b/backends/imgui_impl_opengl3.h"

// namespace PF::PLATFORM{
// class EditorGui{
//   iWindow *window;
//   public:
//     ImGuiEngine(const std::string &path, ENGINE::Window* window);
//     ~ImGuiEngine();
//     void dock(std::function<void()> func);
//     void topBar(std::function<void()> func);
//     void events(SDL_Event event);
//     void render(std::function<void()> func);
// }; // class EditorGui
// }; // namespace PF::PLATFORM