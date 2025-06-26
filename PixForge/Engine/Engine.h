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
  Engine() :renderer(new PF::PLATFORM::Renderer()) {
    editor_gui = new PLATFORM::EditorGui("settings/editor_gui.ini", static_cast<PLATFORM::Renderer*>(renderer));
  };
  ~Engine() { delete editor_gui; delete renderer; };
  void run();
  PLATFORM::iRenderer* getRenderer() { return renderer; };
  PLATFORM::iEditorGui* getEditorGui() { return editor_gui; };
};
}; // namespace PF::ENGINE