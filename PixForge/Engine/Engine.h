#pragma once
#include "Platforms/Platform.h"
#include "STL/Vector/Vector.h"
#include "STL/Math/Vec.h"
#include "Events.h"

namespace PF::ENGINE{
class Engine{
private:
  PLATFORMS::Renderer renderer;
  STL::Vector<EventsCodes> events;
public:
  void run();
  PLATFORMS::Renderer* getRenderer() { return &renderer; };
};
}; // namespace PF::ENGINE