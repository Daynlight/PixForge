#pragma once
#include "../Ui.h"
#include "../TextEditor/TextEditor.h"
#include "Utilities/Tools/Log.h"
#include "STL/Folder/Folder.h"

#define FILE_BOX_WIDTH 100
#define FILE_BOX_BORDER 1
#define FILE_BOX_BORDER_ROUNDING 19

// [BUG] sometimes buttons have same name and this causes errors for imGui, when you open two same files

namespace PF::Forge::Ui{
class FileExplorer : public iUi{
private:
  const uint8_t id;
  STL::Vector<iUi*> *uis;
  STL::Folder folder;
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
  FileExplorer(const uint8_t id, STL::Vector<iUi*> *uis, STL::Folder folder);
  STL::Folder* getFolder() { return &folder; };
public:
  uint8_t getID() override { return id; };
  uint8_t getType() override { return iUi::Type::FILE_EXPLORER; };
  bool isOpen() { return open; };
  void render() override;
};
}; // namespace PF::Forge::Ui
