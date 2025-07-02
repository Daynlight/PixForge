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
  enum WindowType{
    LOG,
    OBJECTS
  };
  Renderer* renderer;
  STL::Vector<WindowGui*> ui;
public:
  EditorGui(const std::string &path, iRenderer* renderer);
  ~EditorGui();
  uint16_t generateUnique();
  void addWindow(WindowType type);
  void dock(std::function<void()> func);
  void topBar();
  void render();
}; // class EditorGui



class WindowLogGui : public WindowGui{
private:
  bool open = true;
  uint16_t id = 0;
public:
  WindowLogGui(uint16_t id) : id(id) {};
  uint16_t getId() { return id; };
  bool isOpen() { return open; };
  void render();
}; // class WindowLogGui


class WindowObjectGui : public WindowGui{
private:
  bool open = true;
  bool add_colour_box = false;
  uint16_t id = 0;
public:
  WindowObjectGui(uint16_t id) : id(id) {};
  uint16_t getId() { return id; };
  bool isOpen() { return open; };
  void render();
}; // class WindowLogGui

}; // namespace PF::PLATFORM



