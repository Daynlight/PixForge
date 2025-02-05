#pragma once
#include "STL/Vector.h"

#include "iUI.h"
#include "LogUI.h"
#include "FileExplorerUI.h"
#include "TextEditorUI.h"

namespace PF{
  class UIManager{
    public:
      Vector<UI*> windows;
    public:
      ~UIManager(){ for(size_t i = 0; i < windows.size(); i++) delete windows[i]; };
      void load(File *file);
      void save(File *file);
  };
};