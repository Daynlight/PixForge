#include "Forge/Forge.h"
#include "Forge/Log.h"

#define BENCHMARK 1

#if BENCHMARK
#include "Debug/Benchmark.h"
#include "Utilities/File/File.h"

int WinMain(){
  PF::Utilities::Log::init(); 
  { 
    PF::Utilities::Benchmark::Allocs allocs("Program Allocs"); 
    PF::FORGE::Forge forge;
    forge.run();
    PF::Utilities::Log::dealloc();
  } 

  PF::UTILITIES::File file = PF::UTILITIES::File("Benchmark.txt");
  for(auto &line : PF::Utilities::Benchmark::Benchmark::get().result)
    file.push(line);
  if(!file.exist()) file.create();
  file.save();
    
  return 0;
};

#else

int WinMain(){
  PF::Utilities::Log::init(); 
  
  PF::FORGE::Forge forge;
  forge.run();
    
  return 0;
};  
#endif
