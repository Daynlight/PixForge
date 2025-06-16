#pragma once
#include "Core.h"
#include <cstdint>

namespace PF::CoreForge::Ui{
class iUi{
public:
  enum Type{
    LOG,
    FILE_EXPLORER,
    TEXT_EDITOR,
    OBJECTS_UI,
    SANDBOX
  };
public:
  static uint8_t generateUniqueID(STL::Vector<iUi*> *uis);
public:
  virtual uint8_t getID() = 0;
  virtual uint8_t getType() = 0;
  virtual bool isOpen() = 0;
  virtual void render() = 0;
};
}; // namespace PF::CoreForge::Ui