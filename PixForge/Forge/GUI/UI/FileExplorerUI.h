#pragma once
#include "GUI/UI/UI.h"
#include "STL/STL.h"
#include "Tools/Log.h"
#include "GUI/UI/TextEditorUI.h"

namespace PF{
  class FileExplorerUI : public UI{
  private:
    const uint8_t ID;
    Folder folder;
    Vector<UI*> *UIs;
    char folderName[128] = "", fileName[128] = "";
    bool createFolder = false, createFile = false;
    bool open = true;
  private:
    inline void popUp();
    inline void fileManager();
    inline void mainMenuBar();
    inline void renderFolder();
  public:
    FileExplorerUI(const uint8_t ID, Vector<UI*> *UIs, Folder folder);
    uint8_t getType() override { return Type::FILE_EXPLORER; };
    uint8_t getID() override { return ID; };
    Folder getFolder() { return folder; };
    bool render() override;
  };
};
