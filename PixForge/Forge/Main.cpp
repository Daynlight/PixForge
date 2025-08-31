#include "Forge/Forge.h"
#include "Forge/Log.h"


int WinMain(){
  PF::Utilities::Log::init(); 
  { 
    PF::FORGE::Forge forge;
    forge.run();
  } 
  PF::Utilities::Log::dealloc();
    
  return 0;
};
