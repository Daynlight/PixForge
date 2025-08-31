#pragma once
#include <functional>
#include "Renderer/Renderer.h"
#include "Debug/Log.h"

#include "imgui.h"
#include "backends/imGui_impl_glfw.h"
#include "backends/imGui_impl_opengl3.h"

namespace PF::FORGE{
class WindowGui{
public:
  virtual void render() = 0;
  virtual uint16_t getId() = 0;
  virtual bool isOpen() = 0;
}; // class WindowLogGui




class Gui{
private:
  enum WindowType{
    LOG,
    OBJECTS
  };

  Renderer* renderer;
  UTILITIES::Vector<WindowGui*> ui;
public:
  Gui(const std::string &path, Renderer* renderer);
  ~Gui();
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
  uint16_t id = 0;
public:
  WindowObjectGui(uint16_t id) : id(id) {};
  uint16_t getId() { return id; };
  bool isOpen() { return open; };
  void render();
}; // class WindowLogGui
}; // namespace PF::PLATFORM



