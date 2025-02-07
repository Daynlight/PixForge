#pragma once
#include "Gui/Ui/Ui.h"
#include "STL/File.h"
#include "Tools/Log.h"

namespace PF{
class TextEditorUI : public iUi{
private:
  const uint8_t id;
  bool open = true;
private:
  char text[1024 * 1024] = ""; // aloc 1 MB of memory
  File file;
private:
  void read();
public:
  TextEditorUI(const uint8_t id, const std::string &path) : id(id), file(path) { read(); Log::log("Text Editor UI Window Opened: " + file.getPath() ); };
  const std::string getPath() { return file.getPath(); };
public:
  uint8_t getID() override { return id; };
  uint8_t getType() override { return iUi::Type::TEXT_EDITOR; };
  bool isOpen() { return open; };
  void render() override;
};
}; // namespace PF