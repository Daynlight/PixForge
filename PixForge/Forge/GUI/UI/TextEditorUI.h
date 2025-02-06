#pragma once
#include "Gui/Ui/iUi.h"

namespace PF{
  class TextEditorUI : public Ui{
    private:
      std::string path;
      const uint8_t ID;
      char text[1024 * 1024] = "";
    private:
      inline void read();
    public:
      TextEditorUI(const uint8_t ID, std::string path);
      bool render() override;
      uint8_t getType() override { return Ui::Type::TEXT_EDITOR; };
      uint8_t getID() override { return ID; };
      std::string getPath() { return path; };
  };
};