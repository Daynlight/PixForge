#include "STL.h"

PF::File::File(const std::string path) :path(path){ file.open(path, std::ios::in | std::ios::out); }
PF::File::~File(){ file.close(); }
std::string& PF::File::operator[](const size_t index){ return data[index]; };
bool PF::File::isEmpty(){ return file.peek() == std::ifstream::traits_type::eof(); }
size_t PF::File::size(){ return data.size(); }
void PF::File::push(const std::string line){ data.push(line); }
void PF::File::clear(){ while(data.size() > 0) data.pop(); }
void PF::File::createFile(){ file.open(path, std::ios::out); }

void PF::File::read(){
  file.seekg(0, std::ios::beg);
  std::string line;
  while(std::getline(file, line)) data.push(line);
}

void PF::File::save(){
  file.close();
  file.open(path, std::ios::out | std::ios::trunc);
  for(int i = 0; i < data.size(); i++) file << data[i] << std::endl;  
  file.close();
  file.open(path, std::ios::in | std::ios::out);
}

PF::Folder::Folder(const std::string path) :path(path){}
std::string &PF::Folder::operator[](const size_t index){ return files[index]; }
bool PF::Folder::exist() { return std::filesystem::exists(path); };
void PF::Folder::createFolder(){ std::filesystem::create_directory(path); }
void PF::Folder::fetchList(){ files.clear(); for(auto& p: std::filesystem::directory_iterator(path)) files.push(p.path().string()); }
std::string PF::Folder::getPath() { return path; }

