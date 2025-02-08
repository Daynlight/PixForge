#include "UiManager.h"

uint8_t PF::iUi::generateUniqueID(Vector<iUi*> *uis){
  uint8_t id = 0;
  for(size_t i = 0; i < uis->size(); i++) if((*uis)[i]->getID() == id) id++;
  return id;
};

void PF::UIManager::load(){
  file.read();
  if(!file.notExist()){
    Vector<Vector<std::string>> records = file.split(';');
    for(size_t i = 0; i < file.size(); i++) {
      Vector<std::string> record = records[i];
      iUi::Type type = static_cast<iUi::Type>(std::stoi(record[0]));
      uint8_t id = std::stoul(record[1]);

      if(type == iUi::Type::LOG) windows.push(new LogUI(id));
      if(type == iUi::Type::FILE_EXPLORER) windows.push(new FileExplorerUI(id, &windows, Folder(record[2])));
      if(type == iUi::Type::TEXT_EDITOR) windows.push(new TextEditorUI(id, record[2]));
      if(type == iUi::Type::OBJECTS_UI) windows.push(new ObjectsUI(id, objects));
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
    Vector<std::string> record;
    record.push(std::to_string(windows[i]->getType()));
    record.push(std::to_string(windows[i]->getID()));
    if(windows[i]->getType() == iUi::Type::FILE_EXPLORER) record.push(static_cast<FileExplorerUI*>(windows[i])->getFolder()->getPath());
    if(windows[i]->getType() == iUi::Type::TEXT_EDITOR) record.push(static_cast<TextEditorUI*>(windows[i])->getPath());
    std::string record_string = record.concat(';');
    file.push(record_string);
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
