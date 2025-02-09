#pragma once
#include <stdio.h>

// [TODO] Write own functions

namespace PF::STL::Convert{
inline int CharInt(const char* value){
  return std::stoi(value);
};
}; // PF::STL::Convert