#pragma once
#include "imgui.h"
#include "STL/STL.h"

namespace PF{
  class Ui{
    public:
      enum Type{
        LOG = 1,
        FILE_EXPLORER,
        TEXT_EDITOR,
        OBJECTS_UI
      };
    public:
      static uint8_t generateUniqueID(Vector<Ui*> *uis);
    public:
      virtual uint8_t getType() = 0;
      virtual uint8_t getID() = 0;
      virtual bool render() = 0;
  };
};