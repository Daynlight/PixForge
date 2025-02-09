#include "Forge/Forge.h"

#include "../Core/STL/File/File.h"

size_t allocationCount = 0;
void* operator new(size_t size){
  allocationCount++;
  return malloc(size);
}

void operator delete(void* memory){
  allocationCount--;
  free(memory);
}

int WinMain(){
  {
    PF::Forge::Forge forge;
    forge.run();
  }

  PF::STL::File file("Allocations.txt");
  file.push("Allocations: " + std::to_string(allocationCount));
  file.save();
  return 0;
};