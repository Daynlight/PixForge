#pragma once
#include <functional>
#include "Platforms/Platform.h"
#include "Utilities/STL/Vector/Vector.h"
#include "Utilities/STL/Math/Vec.h"

namespace PF::ENGINE{
class Engine{
private:
  PLATFORM::iRenderer* renderer = nullptr;
public:
  void Init(const std::string &window_title, int width, int height);
  ~Engine();
  void generateFrame();
  void render();
  void run(std::function<void()> func = nullptr);
  PLATFORM::iRenderer* getRenderer() { return renderer; };
  STL::Vec<int, 4> getWindowRect() { return renderer->getWindowRect(); };
};
}; // namespace PF::ENGINE