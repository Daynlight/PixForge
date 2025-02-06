#pragma once
#include "iUI.h"
#include "STL/Vector.h"
#include "Objects/Object.h"

namespace PF{
  class ObjectsUI : public UI{
    private:
      ObjectManager *objects;
      Vec<int, 4> position = {0, 0, 0, 0};
      Vec<int, 4> colour = {0, 0, 0, 0};
      bool addWindowOpen = false;
    private:
      const uint8_t ID;
    private:
      inline void renderObjectsList();
      inline void renderAddObjectWindow();
    public:
      ObjectsUI(const uint8_t ID, ObjectManager *objects) : ID(ID), objects(objects) {};
    public:
      uint8_t getType() override { return Type::OBJECTS_UI; };
      uint8_t getID() override { return ID; };
      bool render() override;
  };
}