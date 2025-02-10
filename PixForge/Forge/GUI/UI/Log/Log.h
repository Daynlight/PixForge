#pragma once
#include "Gui/Ui/Ui.h"
#include "Tools/Log.h"

namespace PF::Forge::Ui{
class Log : public iUi{
private:
  const uint8_t id;
  bool open = true;
public:
  Log(const uint8_t id) : id(id) { Tools::Log::get().log("Log UI Window Opened"); };
public:
  uint8_t getID() override { return id; };
  uint8_t getType() override { return iUi::Type::LOG; };
  bool isOpen() override { return open; };
  void render() override;
};
}; // namespace PF::Forge::Ui