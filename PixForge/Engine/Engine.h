#pragma once
#include "Platforms/Platform.h"

namespace PF::ENGINE{
class Engine{
private:
  PLATFORMS::Renderer renderer;
public:
  Engine() {};
  PLATFORMS::Renderer* getRenderer() { return &renderer; };
};
}; // namespace PF::ENGINE