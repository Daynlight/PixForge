#include "Log.h"

PF::Utilities::Log* PF::Utilities::Log::instance = nullptr;

void PF::Utilities::Log::init() { if(!instance) instance = new Log();  };
void PF::Utilities::Log::dealloc() { delete instance; };
void PF::Utilities::Log::log(const std::string &text) { get().entry.push(std::pair<char, std::string>(0, "[Log]: " + text)); };
void PF::Utilities::Log::war(const std::string &text) { get().entry.push(std::pair<char, std::string>(1, "[War]: " + text)); };
void PF::Utilities::Log::err(const std::string &text) { get().entry.push(std::pair<char, std::string>(2, "[Err]: " + text)); };
void PF::Utilities::Log::inf(const std::string &text) { get().entry.push(std::pair<char, std::string>(3, "[Inf]: " + text)); }
void PF::Utilities::Log::save(const std::string &path) {
  PF::UTILITIES::File file(path, get().entry.size() + PF::Utilities::Benchmark::Benchmark::get().result.size() + 2);
  file.clear();
  for(unsigned int i = 0; i < PF::Utilities::Benchmark::Benchmark::get().result.size(); i++)
    file.push(PF::Utilities::Benchmark::Benchmark::get().result[i]);
  for(unsigned int i = 0; i < get().entry.size(); i++)
    file.push(get().entry[i].second);
  file.save();
};