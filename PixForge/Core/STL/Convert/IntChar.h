#pragma once
#include <stdio.h>

// [TODO] Write own functions

namespace PF::STL::Convert{
inline char* IntChar(int value){
  char* buffer = new char[12];
  std::snprintf(buffer, 12, "%d", value);
  return buffer;
};
}; // PF::STL::Convert