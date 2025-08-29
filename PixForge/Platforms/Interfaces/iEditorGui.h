#pragma once
#include "Platforms/Interfaces/iRenderer.h"
#include <functional>
#include "Forge/Log.h"

namespace PF::PLATFORM{
class iEditorGui{
  public:
    virtual void dock(std::function<void()> func) = 0;
    virtual void topBar() = 0;
    virtual void render() = 0;
}; // class ImGuiEngine



class WindowGui{
public:
  virtual void render() = 0;
  virtual uint16_t getId() = 0;
  virtual bool isOpen() = 0;
}; // class WindowLogGui
}; // namespace PF::Engine