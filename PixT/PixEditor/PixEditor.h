#pragma once
#include "../Macro.h"
#include "../Assets/Assets.h"
#include "../Assets/Settings.h"
#include "PCRenderer.h"
#include "PCWindow.h"
#include "imgui.h"

namespace PE{
  class Editor{
    private:
      PC::Window window = PC::Window("PixEditor");    
    public:
      void run();
      void editorEvent();
  };
};