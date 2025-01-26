#include "Tools.h"

std::vector<std::pair<char,std::string>> PE::Log::entry;
void PE::Log::log(const std::string text) { entry.emplace_back(0, "[Log]: " + text); };
void PE::Log::war(const std::string text) { entry.emplace_back(1, "[War]: " + text); };
void PE::Log::err(const std::string text) { entry.emplace_back(2, "[Err]: " + text); };
void PE::Log::inf(const std::string text) { entry.emplace_back(3, "[Inf]: " + text); };

void PE::Builder::buildGame(){
  Log::war("Building Game...");
  #ifdef _WIN32
    const char* buildCommand = "start /B cmd.exe /C buildScripts\\build.bat";
  #else
    const char* buildCommand = "bash buildScripts/build.sh &";
  #endif
  system(buildCommand);
  Log::inf("Game Built");
}; 

void PE::Builder::runGame(){
  Log::war("Game Running...");
  #ifdef _WIN32
    const char* runCommand = "start /B cmd.exe /C buildScripts\\run.bat";
  #else
    const char* runCommand = "bash buildScripts/run.sh &";
  #endif
  system(runCommand);
  Log::inf("Game Ran");
};