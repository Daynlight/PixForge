#pragma once
#include <cstring>

// [TODO] Write own functions

namespace PF::STL::Convert{
inline char* UintChar(unsigned int value){
  std::string str = std::to_string(static_cast<int>(value));
  char* cstr = new char[str.length() + 1];
  std::strcpy(cstr, str.c_str());
  return cstr;
};
}; // PF::STL::Convert