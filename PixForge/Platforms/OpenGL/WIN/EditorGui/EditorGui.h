#pragma once
#include "Platforms/Interfaces/iEditorGui.h"
#include "Platforms/OpenGL/WIN/Renderer/Renderer.h"
#include <functional>

#include "Platforms/Vendor/imgui-docking/imgui.h"
#include "Platforms/Vendor/imgui-docking/backends/imgui_impl_glfw.h"
#include "Platforms/Vendor/imgui-docking/backends/imgui_impl_opengl3.h"

namespace PF::PLATFORM{
class EditorGui : public iEditorGui{
private:
  Renderer* renderer;
public:
  EditorGui(const std::string &path, Renderer* renderer);
  ~EditorGui();
  void dock(std::function<void()> func);
  void topBar(std::function<void()> func);
  void events(ENGINE::EventsCodes event);
  void render(std::function<void()> func);
}; // class EditorGui
}; // namespace PF::PLATFORM