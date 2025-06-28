#pragma once
#include <functional>
#include "Platforms/Platform.h"
#include "STL/Vector/Vector.h"
#include "STL/Math/Vec.h"
#include "Events.h"

namespace PF::ENGINE{
class Engine{
private:
  PLATFORM::iRenderer* renderer = nullptr;
  STL::Vector<EventsCodes> events;
public:
  void Init(const std::string &window_title, int width, int height);
  ~Engine();
  void generateFrame();
  void render();
  void run(std::function<void()> func = nullptr);
  void event(EventsCodes event);
  PLATFORM::iRenderer* getRenderer() { return renderer; };
  STL::Vec<int, 4> getWindowRect() { return renderer->getWindowRect(); };
};
}; // namespace PF::ENGINE