#pragma once
#include "Gui/Ui/Ui.h"
#include <fstream>

namespace PF{
class TextEditorUI : public iUi{
private:
  const uint8_t ID;
  bool open = true;
private:
  char text[1024 * 1024] = "";
  std::string path;
private:
  inline void read();
public:
  TextEditorUI(const uint8_t ID, std::string path);
  std::string getPath() { return path; };
public:
  uint8_t getID() override { return ID; };
  uint8_t getType() override { return iUi::Type::TEXT_EDITOR; };
  bool isOpen() { return open; };
  void render() override;
};
}; // namespace PF