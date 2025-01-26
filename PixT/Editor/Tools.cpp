#include "Tools.h"

PC::Vector<std::pair<char,std::string>> PE::Log::entry;
void PE::Log::log(const std::string text) { entry.push(std::pair<char, std::string>(0, "[Log]: " + text)); };
void PE::Log::war(const std::string text) { entry.push(std::pair<char, std::string>(1, "[War]: " + text)); };
void PE::Log::err(const std::string text) { entry.push(std::pair<char, std::string>(2, "[Err]: " + text)); };
void PE::Log::inf(const std::string text) { entry.push(std::pair<char, std::string>(3, "[Inf]: " + text)); };

void PE::Builder::buildGame(){
  Log::war("Building Game...");
  Log::inf("Game Built");
}; 

void PE::Builder::runGame(){
  Log::war("Game Running...");
  Log::inf("Game Ran");
};