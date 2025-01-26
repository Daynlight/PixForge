#pragma once
#include <cstdlib>
#include <vector>
#include <string>

namespace PE{
  struct Log{
      static std::vector<std::pair<char,std::string>> entry;
      static void log(std::string text);
      static void war(std::string text);
      static void err(std::string text);
      static void inf(std::string text);
  };

  class Builder{
    public:
      static void buildGame();
      static void runGame();
  };
};