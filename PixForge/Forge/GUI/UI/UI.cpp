#include "UI.h"

uint8_t PF::UI::generateUniqueID(Vector<UI*> *UIs){
  uint8_t ID = 0;
  for(size_t i = 0; i < UIs->size(); i++) if((*UIs)[i]->getID() == ID) ID++;
  return ID;
};

void PF::UIManager::load(File *file){
  for(size_t i = 0; i < file->size(); i++) {
    std::string record = (*file)[i];
    UI::Type type = static_cast<UI::Type>(record[0]);
    uint8_t ID = record[1];
    if(type == UI::Type::LOG) windows.push(new LogUI(ID));
    if(type == UI::Type::FILE_EXPLORER) windows.push(new FileExplorerUI(ID, &windows, Folder(record.substr(2))));
    if(type == UI::Type::TEXT_EDITOR) windows.push(new TextEditorUI(ID, record.substr(2)));
    if(type == UI::Type::OBJECTS_UI) windows.push(new ObjectsUI(ID, objects));
  };
};

void PF::UIManager::save(File *file){
  for(size_t i = 0; i < windows.size(); i++) {
    std::string record = "";
    record += (char)windows[i]->getType();
    record += (char)windows[i]->getID();
    if(windows[i]->getType() == UI::Type::LOG) record += "";
    if(windows[i]->getType() == UI::Type::FILE_EXPLORER) record += static_cast<FileExplorerUI*>(windows[i])->getFolder().getPath();
    if(windows[i]->getType() == UI::Type::TEXT_EDITOR) record += static_cast<TextEditorUI*>(windows[i])->getPath();
    if(windows[i]->getType() == UI::Type::OBJECTS_UI) record += "";
    file->push(record);
  };
};

void PF::UIManager::addWindow(UI::Type type) {
  if (type == UI::LOG) { windows.push(new LogUI(PF::UI::generateUniqueID(&windows))); };
  if (type == UI::FILE_EXPLORER) { windows.push(new FileExplorerUI(PF::UI::generateUniqueID(&windows), &windows, Folder("assets/"))); };
  if (type == UI::TEXT_EDITOR) { windows.push(new TextEditorUI(PF::UI::generateUniqueID(&windows), "assets/texture/")); };
  if (type == UI::OBJECTS_UI) { windows.push(new ObjectsUI(PF::UI::generateUniqueID(&windows), objects)); };
};
