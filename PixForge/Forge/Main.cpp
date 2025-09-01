#include "Forge/Forge.h"
#include "Debug/Log.h"


int main(){
  PF::Utilities::Log::init(); 
  { 
    PF::FORGE::Forge forge;
    forge.run();
  } 
  PF::Utilities::Log::dealloc();
    
  return 0;
};
