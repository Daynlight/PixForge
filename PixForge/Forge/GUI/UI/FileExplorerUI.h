#pragma once
#include "Gui/Ui/iUi.h"
#include "Tools/Log.h"
#include "Gui/Ui/TextEditorUI.h"

#define FILE_BOX_WIDTH 100
#define FILE_BOX_BORDER 1
#define FILE_BOX_BORDER_ROUNDING 19

namespace PF{
class FileExplorerUI : public Ui{
private:
  const uint8_t ID;
  Vector<Ui*> *uis;
  Folder folder;
  bool open = true;
private:
  char folderName[128] = "", fileName[128] = "";
  bool createFolder = false, createFile = false;
private:
  inline void popUp();
  inline void fileManager();
  inline void mainMenuBar();
  inline void renderFolder();
public:
  FileExplorerUI(const uint8_t ID, Vector<Ui*> *uis, Folder folder);
  Folder* getFolder() { return &folder; };
public:
  uint8_t getID() override { return ID; };
  uint8_t getType() override { return Ui::Type::FILE_EXPLORER; };
  bool isOpen() { return open; };
  void render() override;
};
}; // namespace PF
