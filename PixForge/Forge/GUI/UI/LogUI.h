#pragma once
#include "Gui/Ui/iUi.h"
#include "Tools/Log.h"

namespace PF{
    class LogUI : public Ui{
    private:
      const uint8_t ID;
    public:
      LogUI(const uint8_t ID) : ID(ID) {};
      uint8_t getType() override { return Ui::Type::LOG; };
      uint8_t getID() override { return ID; };
      bool render() override;
  };
}