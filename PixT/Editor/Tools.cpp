#include "Tools.h"

std::vector<std::pair<char,std::string>> PE::Log::entry;
void PE::Log::log(std::string text){ entry.emplace_back(0,"[Log]: "+text);};
void PE::Log::war(std::string text){ entry.emplace_back(1,"[War]: "+text);};
void PE::Log::err(std::string text){ entry.emplace_back(2,"[Err]: "+text);};
void PE::Log::inf(std::string text){ entry.emplace_back(3,"[Inf]: "+text);};

void PE::Builder::buildGame(){
  Log::war("Game Builded");
  #ifdef _WIN32
    std::string buildCommand = "start /B cmd.exe /C buildScripts\\build.bat";
  #else
    std::string buildCommand = "bash buildScripts/build.sh &";
  #endif
  system(buildCommand.c_str());
}; 
void PE::Builder::runGame(){
  Log::war("Game Runed");
  #ifdef _WIN32
    std::string runCommand = "start /B cmd.exe /C buildScripts\\run.bat";
  #else
    std::string runCommand = "bash buildScripts/run.sh &";
  #endif
  system(runCommand.c_str());
};