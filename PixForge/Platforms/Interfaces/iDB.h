#pragma once
#include <string>

namespace PF::PLATFORM{
class iDB{
private:
  std::string path = "";
public:
  virtual void setPath(const std::string& path) = 0;

};
}; // namespace PF::PLATFORM
