#pragma once
#include "Platforms/Interfaces/iDB.h"
#include "Forge/Utilities/Log.h"
#include <string>
#include <vector>
#include "sqlite3.h"

namespace PF::PLATFORM{
class Data : public iDB{
private:
  std::string path = "";
  sqlite3* db = nullptr;

public:
  Data(const std::string& path) { 
    setPath(path); 

  };

  ~Data() override {
    if (db) {
          sqlite3_close(db);
      }
  }

  void setPath(const std::string& path) override { 
    this->path = path; 
    if (sqlite3_open(path.c_str(), &db) != SQLITE_OK)
      Utilities::Log::err(std::string("Failed to open database: ") + sqlite3_errmsg(db));
  };

  std::vector<std::vector<std::string>> select(const std::string& query){

    return std::vector<std::vector<std::string>>();
  };
  void insert(const std::string& query){
    if (!db) {
      Utilities::Log::err("Database not opened.");
      return;
    }

    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);

    if (rc != SQLITE_OK) {
        Utilities::Log::err(std::string("Insert failed: " + std::string(errMsg)));
        sqlite3_free(errMsg);
    }
  };
};
}; // namespace PF::PLATFORM