#pragma once
#include "Gui/Ui/Ui.h"
#include "STL/Vector/Vector.h"
#include "STL/Vec/Vec.h"
#include "Renderer/Objects/Manager.h"
#include "Tools/Log.h"

namespace PF::Forge::Ui{
class Objects : public iUi{
private:
  const uint8_t id;
  bool open = true;
private:
  STL::Vec<int, 4> position = {0, 0, 0, 0};
  STL::Vec<float, 4> colour = {0, 0, 0, 0};
  int texture_index = 0;
private:
  bool add_colour_box = false;
  bool add_sprite = false;
  bool show_properties = false;
  size_t properties_index = 0;
private:
  inline void renderObjectsList();
  inline void renderAddColourBox();
  inline void renderAddSprite();
  inline void renderProperties();
  inline void renderColourBoxProperties();
  inline void renderSpriteProperties();
public:
  Objects(const uint8_t id) : id(id) { Tools::Log::log("Objects UI Window Opened"); };
public:
  uint8_t getID() override { return id; };
  uint8_t getType() override { return Type::OBJECTS_UI; };
  bool isOpen() override { return open; };
  void render() override;
};
}; // namespace PF::Forge::Ui