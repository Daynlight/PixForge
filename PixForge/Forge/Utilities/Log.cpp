#include "Log.h"

PF::Utilities::Log* PF::Utilities::Log::instance = nullptr;

void PF::Utilities::Log::init() { if(!instance) instance = new Log(); };
void PF::Utilities::Log::dealloc() { delete instance; };
void PF::Utilities::Log::log(const std::string &text) { get().entry.push(std::pair<char, std::string>(0, "[Log]: " + text)); };
void PF::Utilities::Log::war(const std::string &text) { get().entry.push(std::pair<char, std::string>(1, "[War]: " + text)); };
void PF::Utilities::Log::err(const std::string &text) { get().entry.push(std::pair<char, std::string>(2, "[Err]: " + text)); };
void PF::Utilities::Log::inf(const std::string &text) { get().entry.push(std::pair<char, std::string>(3, "[Inf]: " + text)); };