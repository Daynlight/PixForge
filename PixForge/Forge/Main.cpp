#include "Forge/Forge.h"

#define BENCHMARK 1

#if BENCHMARK
#include "Benchmark.h"
#include "../Core/STL/File/File.h"
#endif

int WinMain(){
  #if BENCHMARK
  { Benchmark::Allocs allocs("Program Allocs");
  #endif
  PF::Forge::Forge forge;
  forge.run();
  
  #if BENCHMARK
  } PF::STL::File file = PF::STL::File("Benchmark.txt");
  for(auto &line : Benchmark::Benchmark::get().result)
    file.push(line);
  if(file.notExist()) file.createFile();
  file.save();
  #endif
  return 0;
};