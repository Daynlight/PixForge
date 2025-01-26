#pragma once
#include <cstdlib>
#include <vector>
#include <string>

namespace PE{
  struct Log{
    static std::vector<std::pair<char, std::string>> entry;
    static void log(const std::string text);
    static void war(const std::string text);
    static void err(const std::string text);
    static void inf(const std::string text);
  };

  class Builder{
    public:
      static void buildGame();
      static void runGame();
  };
};