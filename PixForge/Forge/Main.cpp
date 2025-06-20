#include "Forge/Forge.h"
#include "Utilities/Log.h"

#define BENCHMARK 1

#if BENCHMARK
#include "Utilities/Benchmark.h"
#include "STL/File/File.h"
#endif

int WinMain(){
  PF::Utilities::Log::init();
  
  #if BENCHMARK
  { PF::Utilities::Benchmark::Allocs allocs("Program Allocs");
  #endif
  
  {  
    PF::FORGE::Forge forge;
    forge.run();
  }
  
  #if BENCHMARK
  PF::Utilities::Log::dealloc();
  
  } PF::STL::File file = PF::STL::File("Benchmark.txt");
  for(auto &line : PF::Utilities::Benchmark::Benchmark::get().result)
    file.push(line);
  if(!file.exist()) file.create();
  file.save();
  #endif
  
  return 0;
};