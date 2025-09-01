#pragma once
#include <functional>
#include <filesystem>
#include "Platforms/Platform.h"
#include "Utilities/Vector/Vector.h"
#include "Utilities/Math/Vec.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <dlfcn.h>
#endif

namespace PF::ENGINE{
class Engine{
private:
  PLATFORM::iRenderer* renderer = nullptr;
public:
  void Init(const std::string &window_title, int width, int height, bool for_editor = false);
  ~Engine();
  PF::UTILITIES::Vector<std::string> getRenderers();
  void loadRenderer(const std::string& dllPath); 
  void generateFrame();
  void render();
  void run(std::function<void()> func = nullptr);
  void events();
  PLATFORM::iRenderer* getRenderer() { return renderer; };
  UTILITIES::Vec<int, 4> getWindowRect() { return renderer->getWindowRect(); };
};
}; // namespace PF::ENGINE