#pragma once
#include "Core.h"
#include "Sandbox/Sandbox.h"

#include "Ui.h"
#include "Log/Log.h"
#include "FileExplorer/FileExplorer.h"
#include "TextEditor/TextEditor.h"
#include "Objects/Objects.h"
#include "SandboxWindow/SandboxWindow.h"

namespace PF::CoreForge::Ui{
class Manager{
public:
  STL::Vector<Ui::iUi*> windows;
  STL::File file;
  Sandbox *sandbox = nullptr;
public:
  Manager(const std::string& path, Sandbox *sandbox) : file(path), sandbox(sandbox) {};
  ~Manager(){ while(windows.size()) delete windows.pop(); };
  void load();
  void save();
  void addWindow(Ui::iUi::Type type);
};
}; // namespace PF::CoreForge