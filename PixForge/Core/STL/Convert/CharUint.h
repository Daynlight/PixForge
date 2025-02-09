#pragma once
#include <stdio.h>

// [TODO] Write own functions

namespace PF::STL::Convert{
inline unsigned int CharUint(const char* value){
  return std::stoul(value);
};
}; // PF::STL::Convert