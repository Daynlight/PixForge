#pragma once
#include "../Settings.h"
#include "PCWindow.h"
#include "imgui.h"

namespace PE{
  class Editor{
    private:
      PC::Window window = PC::Window("PixEditor");    
    public:
      void run();
  };
};