#include "Manager.h"

uint8_t PF::Forge::Ui::iUi::generateUniqueID(STL::Vector<iUi*> *uis){
  uint8_t id = 0;
  for(size_t i = 0; i < uis->size(); i++) if((*uis)[i]->getID() == id) id++;
  return id;
};

void PF::Forge::Ui::Manager::load(){
  file.read();
  if(file.exist()){
    STL::Vector<STL::Vector<std::string>*> records = file.split(';');
    for(size_t i = 0; i < file.size(); i++) {
      STL::Vector<std::string>* record = records[i];
      iUi::Type type = static_cast<iUi::Type>(std::stoi((*record)[0]));
      uint8_t id = std::stoul((*record)[1]);

      if(type == Ui::iUi::Type::LOG) windows.push(new Ui::Log(id));
      if(type == Ui::iUi::Type::FILE_EXPLORER) windows.push(new Ui::FileExplorer(id, &windows, STL::Folder((*record)[2])));
      if(type == Ui::iUi::Type::TEXT_EDITOR) windows.push(new Ui::TextEditor(id, (*record)[2]));
      if(type == Ui::iUi::Type::OBJECTS_UI) windows.push(new Ui::Objects(id));

      delete record;
    };
  };
  Tools::Log::inf("UI Windows Loaded: "+std::to_string(windows.size()));
};

void PF::Forge::Ui::Manager::save(){
  if(!file.exist()) {
    file.create();
    Tools::Log::war("gui_window file Created");
  };

  file.clear();
  for(size_t i = 0; i < windows.size(); i++) {
    STL::Vector<std::string> record;
    record.push(std::to_string(windows[i]->getType()));
    record.push(std::to_string(windows[i]->getID()));
    if(windows[i]->getType() == iUi::Type::FILE_EXPLORER) record.push(static_cast<FileExplorer*>(windows[i])->getFolder()->getPath());
    if(windows[i]->getType() == iUi::Type::TEXT_EDITOR) record.push(static_cast<TextEditor*>(windows[i])->getPath());
    std::string record_string = record.concat(';');
    file.push(record_string);
  };

  file.save();
  Tools::Log::inf("UI Windows Saved: "+std::to_string(windows.size()));
};

void PF::Forge::Ui::Manager::addWindow(iUi::Type type) {
  if (type == iUi::LOG) { windows.push(new Log(iUi::generateUniqueID(&windows))); };
  if (type == iUi::FILE_EXPLORER) { windows.push(new FileExplorer(iUi::generateUniqueID(&windows), &windows, STL::Folder("assets/"))); };
  if (type == iUi::TEXT_EDITOR) { windows.push(new TextEditor(iUi::generateUniqueID(&windows), "assets/texture/")); };
  if (type == iUi::OBJECTS_UI) { windows.push(new Objects(iUi::generateUniqueID(&windows))); };
};
