#pragma once
#include "Gui/Ui/Ui.h"
#include "Tools/Log.h"
#include "Gui/Ui/TextEditorUi.h"
#include "STL/Folder.h"

#define FILE_BOX_WIDTH 100
#define FILE_BOX_BORDER 1
#define FILE_BOX_BORDER_ROUNDING 19

// [BUG] on file remove program crashes when file isOpen 

namespace PF{
class FileExplorerUI : public iUi{
private:
  const uint8_t id;
  Vector<iUi*> *uis;
  Folder folder;
  bool open = true;
private:
  char folder_name[128] = "", file_name[128] = "";
  bool create_folder = false, create_file = false;
private:
  inline void popUp();
  inline void fileManager();
  inline void mainMenuBar();
  inline void renderFolder();
public:
  FileExplorerUI(const uint8_t id, Vector<iUi*> *uis, Folder folder);
  Folder* getFolder() { return &folder; };
public:
  uint8_t getID() override { return id; };
  uint8_t getType() override { return iUi::Type::FILE_EXPLORER; };
  bool isOpen() { return open; };
  void render() override;
};
}; // namespace PF
