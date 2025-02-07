#pragma once
#include "STL/Vector.h"

namespace PF{
  struct Log{
    static Vector<std::pair<char, std::string>> entry;
    static void log(const std::string text);
    static void war(const std::string text);
    static void err(const std::string text);
    static void inf(const std::string text);
  };
};