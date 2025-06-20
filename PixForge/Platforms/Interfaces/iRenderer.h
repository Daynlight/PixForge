#pragma once
#include <string>

namespace PF::PLATFORMS{
class iRenderer{
public:
  virtual void createWindow(const std::string &title) = 0;
  virtual bool isRunning() = 0;
};
}; // namespace PF::PLATFORM