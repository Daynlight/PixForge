#pragma once
#include <string>
#include "STL/Vector/Vector.h"
#include "Engine/Events.h"

namespace PF::PLATFORMS{
class iRenderer{
public:
  virtual void createWindow(const std::string &title) = 0;
  virtual bool isRunning() = 0;
  virtual void pullEvents(STL::Vector<PF::ENGINE::EventsCodes> &events) = 0;
  virtual void proccessEvent(const PF::ENGINE::EventsCodes) = 0;
};
}; // namespace PF::PLATFORM