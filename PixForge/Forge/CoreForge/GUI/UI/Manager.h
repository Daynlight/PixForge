#pragma once
#include "STL/Vector/Vector.h"
#include "Renderer/Objects/Manager.h"

#include "Ui.h"
#include "Log/Log.h"
#include "FileExplorer/FileExplorer.h"
#include "TextEditor/TextEditor.h"
#include "Objects/Objects.h"

namespace PF::CoreForge::Ui{
class Manager{
public:
  STL::Vector<Ui::iUi*> windows;
  STL::File file;
public:
  Manager(const std::string& path) : file(path) {};
  ~Manager(){ while(windows.size()) delete windows.pop(); };
  void load();
  void save();
  void addWindow(Ui::iUi::Type type);
};
}; // namespace PF::CoreForge