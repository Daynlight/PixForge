#pragma once
#include "STL/Vector/Vector.h"

namespace PF::Tools{
class Log{
private:
  static Log *instance;
public:
  static void init() { if(!instance) instance = new Log(); }
  static void dealloc() { delete instance; }
  static Log &get() { init(); return *instance; }
  Log(Log &log) = delete;
  Log operator=(Log &log) = delete;
public:
  Log() {};
  ~Log() {};
  STL::Vector<std::pair<char, std::string>> entry;
  void log(const std::string &text);
  void war(const std::string &text);
  void err(const std::string &text);
  void inf(const std::string &text);
};
};