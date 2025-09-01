#pragma once
#include <string>
#include <vector>
#include "Debug/Log.h"

namespace PF::PLATFORM{
class iSQL{
private:
  std::string path = "";
public:
  virtual ~iSQL() = default;
  virtual void setPath(const std::string& path) = 0;
  virtual std::vector<std::vector<std::string>> select(const std::string& query) = 0;
  virtual void insert(const std::string& query) = 0;
public:
  virtual std::vector<std::vector<std::string>> getProjects(const std::string& nick) = 0;
};
}; // namespace PF::PLATFORM

extern "C" PF::PLATFORM::iSQL* CreateData();