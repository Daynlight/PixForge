#pragma once
#include "imgui.h"
#include "STL/Vector.h"
#include <cstdint>

namespace PF{
class Ui{
public:
  enum Type{
    LOG,
    FILE_EXPLORER,
    TEXT_EDITOR,
    OBJECTS_UI
  };
public:
  static uint8_t generateUniqueID(Vector<Ui*> *uis);
public:
  virtual uint8_t getID() = 0;
  virtual uint8_t getType() = 0;
  virtual bool isOpen() = 0;
  virtual void render() = 0;
};
}; // namespace PF