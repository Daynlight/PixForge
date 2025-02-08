#pragma once
#include "STL/Vector.h"
#include "Renderer/Objects/ObjectManager.h"

#include "Ui.h"
#include "LogUi.h"
#include "FileExplorerUi.h"
#include "TextEditorUi.h"
#include "ObjectsUi.h"

namespace PF{
class UIManager{
public:
  Vector<iUi*> windows;
  ObjectManager *objects;
  File file;
public:
  UIManager(ObjectManager *objects, const std::string& path) : objects(objects), file(path) {};
  ~UIManager(){ for(size_t i = 0; i < windows.size(); i++) delete windows[i]; };
  void load();
  void save();
  void addWindow(iUi::Type type);
};
}; // namespace PF