#include "UI.h"

uint8_t PF::Ui::generateUniqueID(Vector<Ui*> *uis){
  uint8_t ID = 0;
  for(size_t i = 0; i < uis->size(); i++) if((*uis)[i]->getID() == ID) ID++;
  return ID;
};

void PF::UIManager::load(File *file){
  file->read();
  if(!file->notExist()){
    for(size_t i = 0; i < file->size(); i++) {
      std::string record = (*file)[i];
      Ui::Type type = static_cast<Ui::Type>(record[0]);
      uint8_t ID = record[1];
      if(type == Ui::Type::LOG) windows.push(new LogUI(ID));
      if(type == Ui::Type::FILE_EXPLORER) windows.push(new FileExplorerUI(ID, &windows, Folder(record.substr(2))));
      if(type == Ui::Type::TEXT_EDITOR) windows.push(new TextEditorUI(ID, record.substr(2)));
      if(type == Ui::Type::OBJECTS_UI) windows.push(new ObjectsUI(ID, objects));
    };
  };
};

void PF::UIManager::save(File *file){
  if(file->notExist()) {
    file->createFile();
    Log::war("gui_window file Created");
  };

  file->clear();
  for(size_t i = 0; i < windows.size(); i++) {
    std::string record = "";
    record += (char)windows[i]->getType();
    record += (char)windows[i]->getID();
    if(windows[i]->getType() == Ui::Type::LOG) record += "";
    if(windows[i]->getType() == Ui::Type::FILE_EXPLORER) record += static_cast<FileExplorerUI*>(windows[i])->getFolder().getPath();
    if(windows[i]->getType() == Ui::Type::TEXT_EDITOR) record += static_cast<TextEditorUI*>(windows[i])->getPath();
    if(windows[i]->getType() == Ui::Type::OBJECTS_UI) record += "";
    file->push(record);
  };

  file->save();
};

void PF::UIManager::addWindow(Ui::Type type) {
  if (type == Ui::LOG) { windows.push(new LogUI(PF::Ui::generateUniqueID(&windows))); };
  if (type == Ui::FILE_EXPLORER) { windows.push(new FileExplorerUI(PF::Ui::generateUniqueID(&windows), &windows, Folder("assets/"))); };
  if (type == Ui::TEXT_EDITOR) { windows.push(new TextEditorUI(PF::Ui::generateUniqueID(&windows), "assets/texture/")); };
  if (type == Ui::OBJECTS_UI) { windows.push(new ObjectsUI(PF::Ui::generateUniqueID(&windows), objects)); };
};
