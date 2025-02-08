#include "Log.h"

PF::STL::Vector<std::pair<char,std::string>> PF::Tools::Log::entry;
void PF::Tools::Log::log(const std::string text) { entry.push(std::pair<char, std::string>(0, "[Log]: " + text)); };
void PF::Tools::Log::war(const std::string text) { entry.push(std::pair<char, std::string>(1, "[War]: " + text)); };
void PF::Tools::Log::err(const std::string text) { entry.push(std::pair<char, std::string>(2, "[Err]: " + text)); };
void PF::Tools::Log::inf(const std::string text) { entry.push(std::pair<char, std::string>(3, "[Inf]: " + text)); };