#pragma once
#include "Platforms/Platform.h"
#include "STL/Vector/Vector.h"
#include "STL/Math/Vec.h"
#include "Events.h"

namespace PF::ENGINE{
class Engine{
private:
  PLATFORM::iRenderer* renderer = nullptr;
  PLATFORM::iEditorGui* editor_gui = nullptr;
  STL::Vector<EventsCodes> events;
public:
  void Init(const std::string &window_title);
  ~Engine();
  void run();
  PLATFORM::iRenderer* getRenderer() { return renderer; };
  PLATFORM::iEditorGui* getEditorGui() { return editor_gui; };
};
}; // namespace PF::ENGINE