#pragma once
#include "STL/Vector.h"
#include "Objects/Object.h"

#include "iUI.h"
#include "LogUI.h"
#include "FileExplorerUI.h"
#include "TextEditorUI.h"
#include "ObjectsUI.h"

namespace PF{
  class UIManager{
    public:
      Vector<UI*> windows;
      ObjectManager *objects;
    public:
      UIManager(ObjectManager *objects) : objects(objects) {};
      ~UIManager(){ for(size_t i = 0; i < windows.size(); i++) delete windows[i]; };
      void load(File *file);
      void save(File *file);
      void addWindow(UI::Type type);
  };
};