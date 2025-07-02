#pragma once
#include "Platforms/Interfaces/iRenderer.h"
#include <functional>
#include "Engine/Events.h"

namespace PF::PLATFORM{
class iEditorGui{
  public:
    virtual void dock(std::function<void()> func) = 0;
    virtual void topBar() = 0;
    virtual void render() = 0;
}; // class ImGuiEngine
}; // namespace PF::Engine