#include "Log.h"

PF::Vector<std::pair<char,std::string>> PF::Log::entry;
void PF::Log::log(const std::string text) { entry.push(std::pair<char, std::string>(0, "[Log]: " + text)); };
void PF::Log::war(const std::string text) { entry.push(std::pair<char, std::string>(1, "[War]: " + text)); };
void PF::Log::err(const std::string text) { entry.push(std::pair<char, std::string>(2, "[Err]: " + text)); };
void PF::Log::inf(const std::string text) { entry.push(std::pair<char, std::string>(3, "[Inf]: " + text)); };

void PF::Builder::buildGame(){
  Log::war("Building Game...");
  Log::inf("Game Built");
}; 

void PF::Builder::runGame(){
  Log::war("Game Running...");
  system("start /B Game.exe");
  Log::inf("Game Ran");
};