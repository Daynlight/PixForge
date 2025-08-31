#include "Log.h"

inline PF::Utilities::Log* PF::Utilities::Log::instance = nullptr;

inline void PF::Utilities::Log::init() { if(!instance) instance = new Log();  };
inline void PF::Utilities::Log::dealloc() { delete instance; };
inline void PF::Utilities::Log::log(const std::string &text) { get().entry.push(std::pair<char, std::string>(0, "[Log]: " + text)); };
inline void PF::Utilities::Log::war(const std::string &text) { get().entry.push(std::pair<char, std::string>(1, "[War]: " + text)); };
inline void PF::Utilities::Log::err(const std::string &text) { get().entry.push(std::pair<char, std::string>(2, "[Err]: " + text)); };
inline void PF::Utilities::Log::inf(const std::string &text) { get().entry.push(std::pair<char, std::string>(3, "[Inf]: " + text)); }
inline void PF::Utilities::Log::save(const std::string &path) {
  PF::UTILITIES::File file(path, get().entry.size() + PF::Utilities::Benchmark::Benchmark::get().result.size() + 2);
  file.clear();
  for(unsigned int i = 0; i < PF::Utilities::Benchmark::Benchmark::get().result.size(); i++)
    file.push(PF::Utilities::Benchmark::Benchmark::get().result[i]);
  for(unsigned int i = 0; i < get().entry.size(); i++)
    file.push(get().entry[i].second);
  file.save();
};