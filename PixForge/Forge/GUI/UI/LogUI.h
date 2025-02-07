#pragma once
#include "Gui/Ui/iUi.h"
#include "Tools/Log.h"

namespace PF{
class LogUI : public Ui{
private:
  const uint8_t ID;
  bool open = true;
public:
  LogUI(const uint8_t ID) : ID(ID) {};
public:
  uint8_t getID() override { return ID; };
  uint8_t getType() override { return Ui::Type::LOG; };
  bool isOpen() override { return open; };
  void render() override;
};
}; // namespace PF