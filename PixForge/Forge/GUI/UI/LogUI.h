#pragma once
#include "GUI/UI/iUI.h"
#include "Tools/Log.h"

namespace PF{
    class LogUI : public UI{
    private:
      const uint8_t ID;
    public:
      LogUI(const uint8_t ID) : ID(ID) {};
      uint8_t getType() override { return UI::Type::LOG; };
      uint8_t getID() override { return ID; };
      bool render() override;
  };
}