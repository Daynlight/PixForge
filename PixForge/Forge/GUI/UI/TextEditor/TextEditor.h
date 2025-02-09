#pragma once
#include "Gui/Ui/Ui.h"
#include "STL/File/File.h"
#include "Tools/Log.h"

namespace PF::Forge::Ui{
class TextEditor : public iUi{
private:
  const uint8_t id;
  bool open = true;
private:
  char text[1024 * 1024] = ""; // aloc 1 MB of memory
  STL::File file;
private:
  void read();
public:
TextEditor(const uint8_t id, const std::string &path) : id(id), file(path) { read(); Tools::Log::log("Text Editor UI Window Opened: " + file.getPath() ); };
  const std::string getPath() { return file.getPath(); };
public:
  uint8_t getID() override { return id; };
  uint8_t getType() override { return iUi::Type::TEXT_EDITOR; };
  bool isOpen() { return open; };
  void render() override;
};
}; // namespace PF::Forge::Ui