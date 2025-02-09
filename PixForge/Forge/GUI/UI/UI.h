#pragma once
#include "STL/Vector/Vector.h"
#include "imgui.h"
#include <cstdint>

namespace PF::Forge::Ui{
class iUi{
public:
  enum Type{
    LOG,
    FILE_EXPLORER,
    TEXT_EDITOR,
    OBJECTS_UI
  };
public:
  static uint8_t generateUniqueID(STL::Vector<iUi*> *uis);
public:
  virtual uint8_t getID() = 0;
  virtual uint8_t getType() = 0;
  virtual bool isOpen() = 0;
  virtual void render() = 0;
};
}; // namespace PF::Forge::Ui