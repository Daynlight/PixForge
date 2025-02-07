#include "UiManager.h"

uint8_t PF::iUi::generateUniqueID(Vector<iUi*> *uis){
  uint8_t id = 0;
  for(size_t i = 0; i < uis->size(); i++) if((*uis)[i]->getID() == id) id++;
  return id;
};

void PF::UIManager::load(){
  file.read();
  if(!file.notExist()){
    for(size_t i = 0; i < file.size(); i++) {
      std::string record = file[i];
      iUi::Type type = static_cast<iUi::Type>(record[0]);
      uint8_t ID = record[1];
      if(type == iUi::Type::LOG) windows.push(new LogUI(ID));
      if(type == iUi::Type::FILE_EXPLORER) windows.push(new FileExplorerUI(ID, &windows, Folder(record.substr(2))));
      if(type == iUi::Type::TEXT_EDITOR) windows.push(new TextEditorUI(ID, record.substr(2)));
      if(type == iUi::Type::OBJECTS_UI) windows.push(new ObjectsUI(ID, objects));
    };
  };
  Log::inf("UI Windows Loaded: "+std::to_string(windows.size()));
};

void PF::UIManager::save(){
  if(file.notExist()) {
    file.createFile();
    Log::war("gui_window file Created");
  };

  file.clear();
  for(size_t i = 0; i < windows.size(); i++) {
    std::string record = "";
    record += (char)windows[i]->getType();
    record += (char)windows[i]->getID();
    if(windows[i]->getType() == iUi::Type::LOG) record += "";
    if(windows[i]->getType() == iUi::Type::FILE_EXPLORER) record += static_cast<FileExplorerUI*>(windows[i])->getFolder()->getPath();
    if(windows[i]->getType() == iUi::Type::TEXT_EDITOR) record += static_cast<TextEditorUI*>(windows[i])->getPath();
    if(windows[i]->getType() == iUi::Type::OBJECTS_UI) record += "";
    file.push(record);
  };

  file.save();
  Log::inf("UI Windows Saved: "+std::to_string(windows.size()));
};

void PF::UIManager::addWindow(iUi::Type type) {
  if (type == iUi::LOG) { windows.push(new LogUI(PF::iUi::generateUniqueID(&windows))); };
  if (type == iUi::FILE_EXPLORER) { windows.push(new FileExplorerUI(PF::iUi::generateUniqueID(&windows), &windows, Folder("assets/"))); };
  if (type == iUi::TEXT_EDITOR) { windows.push(new TextEditorUI(PF::iUi::generateUniqueID(&windows), "assets/texture/")); };
  if (type == iUi::OBJECTS_UI) { windows.push(new ObjectsUI(PF::iUi::generateUniqueID(&windows), objects)); };
};
