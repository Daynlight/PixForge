#pragma once
#include "Platforms/Interfaces/iSQL.h"
#include "Forge/Utilities/Log.h"
#include <string>
#include <vector>
#include "sqlite3.h"

namespace PF::PLATFORM{
class SQL : public iSQL{
private:
std::string path = "";
sqlite3* db = nullptr;

private:
SQL() = default;
SQL(const SQL&) = delete;
SQL& operator=(const SQL&) = delete;

public:
static SQL& get() 
{
  static SQL instance;
  return instance;
};

~SQL() override {
  if (db) sqlite3_close(db);
}

void setPath(const std::string& path) override { 
  this->path = path; 
  if (sqlite3_open(path.c_str(), &db) != SQLITE_OK)
    Utilities::Log::err(std::string("Failed to open database: ") + sqlite3_errmsg(db));
};

std::vector<std::vector<std::string>> select(const std::string& query) override {
  std::vector<std::vector<std::string>> results;
  if (!db) {
    Utilities::Log::err("Database not opened.");
    return results;
  }

  sqlite3_stmt* stmt = nullptr;
  int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
  if (rc != SQLITE_OK) {
    Utilities::Log::err(std::string("Failed to prepare statement: ") + sqlite3_errmsg(db));
    return results;
  }

  int cols = sqlite3_column_count(stmt);
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    std::vector<std::string> row;
    for (int i = 0; i < cols; ++i) {
      const unsigned char* text = sqlite3_column_text(stmt, i);
      row.push_back(text ? reinterpret_cast<const char*>(text) : "");
    }
    results.push_back(std::move(row));
  }

  if (rc != SQLITE_DONE)
    Utilities::Log::err(std::string("Failed to execute query: ") + sqlite3_errmsg(db));

  sqlite3_finalize(stmt);
  return results;
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