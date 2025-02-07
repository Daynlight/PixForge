#pragma once
#include "Gui/Ui/Ui.h"
#include "Tools/Log.h"

namespace PF{
class LogUI : public iUi{
private:
  const uint8_t id;
  bool open = true;
public:
  LogUI(const uint8_t id) : id(id) {};
public:
  uint8_t getID() override { return id; };
  uint8_t getType() override { return iUi::Type::LOG; };
  bool isOpen() override { return open; };
  void render() override;
};
}; // namespace PF