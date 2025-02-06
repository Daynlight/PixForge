#pragma once
#include "imgui.h"
#include "STL/STL.h"

namespace PF{
  class UI{
    public:
      enum Type{
        LOG = 1,
        FILE_EXPLORER = 2,
        TEXT_EDITOR = 3,
        OBJECTS_UI = 4
      };
    public:
      static uint8_t generateUniqueID(Vector<UI*> *UIs);
    public:
      virtual uint8_t getType() = 0;
      virtual uint8_t getID() = 0;
      virtual bool render() = 0;
  };
};