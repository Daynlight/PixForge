#pragma once
#include <string>
#include <vector>
#include "Forge/Utilities/Log.h"

namespace PF::PLATFORM{
class iDB{
private:
  std::string path = "";
public:
  virtual ~iDB() = default;
  virtual void setPath(const std::string& path) = 0;
  virtual std::vector<std::vector<std::string>> select(const std::string& query) = 0;
  virtual void insert(const std::string& query) = 0;
};
}; // namespace PF::PLATFORM
