#pragma once
#include "STL/Vector/Vector.h"

namespace PF::Utilities{
class Log{
private:
  static Log *instance;
  STL::Vector<std::pair<char, std::string>> entry;
public:
  static Log &get() { init(); return *instance; };
  static void init();
  static void dealloc();
  Log(Log &log) = delete;
  Log operator=(Log &log) = delete;
  Log() {};
  ~Log() {};
public:
  static const std::pair<char, std::string> &at(const unsigned int &index) { return get().entry[index]; };
  static const unsigned int size() { return get().entry.size(); };
  static void log(const std::string &text);
  static void war(const std::string &text);
  static void err(const std::string &text);
  static void inf(const std::string &text);
}; // class Log
}; // namespace PF::Tools