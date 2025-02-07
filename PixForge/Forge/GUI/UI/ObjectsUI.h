#pragma once
#include "Ui.h"
#include "STL/Vector.h"
#include "Objects/Object.h"

namespace PF{
class ObjectsUI : public iUi{
private:
  const uint8_t ID;
  bool open = true;
private:
  ObjectManager *objects;
  Vec<int, 4> position = {0, 0, 0, 0};
  Vec<float, 4> colour = {0, 0, 0, 0};
  bool addColourBox = false;
  bool showProperties = false;
  size_t propertiesIndex = 0;
private:
  inline void renderObjectsList();
  inline void renderAddColourBox();
  inline void renderProperties();
  inline void renderColourBoxProperties();
public:
  ObjectsUI(const uint8_t ID, ObjectManager *objects) : ID(ID), objects(objects) {};
public:
  uint8_t getID() override { return ID; };
  uint8_t getType() override { return Type::OBJECTS_UI; };
  bool isOpen() override { return open; };
  void render() override;
};
};