#include "Forge/Forge.h"
#include "Debug/Log.h"


#ifdef _WIN32
int WinMain() {
#else
int main() {
#endif
  PF::Utilities::Log::init(); 
  { 
    PF::FORGE::Forge forge;
    forge.run();
  } 
  PF::Utilities::Log::dealloc();
    
  return 0;
};
