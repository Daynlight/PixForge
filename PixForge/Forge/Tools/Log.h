#pragma once
#include "STL/Vector/Vector.h"

namespace PF::Tools{
class Log{
private:
  static Log *instance;
public:
  static Log &get() { init(); return *instance; }
  static void init();
  static void dealloc();
  Log(Log &log) = delete;
  Log operator=(Log &log) = delete;
public:
  Log() {};
  ~Log() {};
private:
  STL::Vector<std::pair<char, std::string>> entry;
public:
  static const STL::Vector<std::pair<char, std::string>> &getEntry() { return get().entry; };
  static void log(const std::string &text);
  static void war(const std::string &text);
  static void err(const std::string &text);
  static void inf(const std::string &text);
};
};