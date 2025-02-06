#pragma once
#include "Gui/Ui/iUi.h"
#include "STL/STL.h"
#include "Tools/Log.h"
#include "Gui/Ui/TextEditorUI.h"

#define FILE_BOX_WIDTH 100
#define FILE_BOX_BORDER 1
#define FILE_BOX_BORDER_ROUNDING 19

namespace PF{
  class FileExplorerUI : public Ui{
  private:
    const uint8_t ID;
    Folder folder;
    Vector<Ui*> *uis;
    char folderName[128] = "", fileName[128] = "";
    bool createFolder = false, createFile = false;
    bool open = true;
  private:
    inline void popUp();
    inline void fileManager();
    inline void mainMenuBar();
    inline void renderFolder();
  public:
    FileExplorerUI(const uint8_t ID, Vector<Ui*> *uis, Folder folder);
    uint8_t getType() override { return Ui::Type::FILE_EXPLORER; };
    uint8_t getID() override { return ID; };
    Folder getFolder() { return folder; };
    bool render() override;
  };
};
