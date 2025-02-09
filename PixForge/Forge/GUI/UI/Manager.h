#pragma once
#include "STL/Vector/Vector.h"
#include "Renderer/Objects/Manager.h"

#include "Gui/Ui/Ui.h"
#include "Log/Log.h"
#include "FileExplorer/FileExplorer.h"
#include "TextEditor/TextEditor.h"
#include "Objects/Objects.h"

namespace PF::Forge::Ui{
class Manager{
public:
  STL::Vector<Ui::iUi*> windows;
  Core::Renderer::Objects::Manager *objects;
  STL::File file;
public:
  Manager(const std::string& path) : file(path) {};
  ~Manager(){ for(size_t i = 0; i < windows.size(); i++) delete windows[i]; };
  void load();
  void save();
  void addWindow(Ui::iUi::Type type);
};
}; // namespace PF::Forge