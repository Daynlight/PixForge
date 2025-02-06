#pragma once
#include "Window/Window.h"

namespace PF{
  class Object{
    public:
      virtual void render(Window *window) = 0;
  };
};