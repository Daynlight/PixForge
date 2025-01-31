#include "Folder.h"

PF::Folder::Folder(const std::string path) :path(path){};

std::pair<char, std::string> &PF::Folder::operator[](const size_t index){ return files[index]; };

bool PF::Folder::exist() { return std::filesystem::exists(path); };

void PF::Folder::createFolder(){ std::filesystem::create_directory(path); };

PF::File PF::Folder::openFile(const std::string file) { return File(path + file); }

void PF::Folder::remove(const std::string file) { std::filesystem::remove_all(path + file); };

PF::Folder PF::Folder::openFolder(const std::string folder) { return Folder(path + folder); };

PF::Folder PF::Folder::back(){
  std::string temp = path;
  temp.pop_back();
  while(temp.size() != 0 && temp.back() != '/') 
    temp.pop_back();
  if(temp.size()) return Folder(temp);
  return Folder(path);
};

std::string PF::Folder::getPath() { return path; };

void PF::Folder::fetchList() {
  files.clear(); 
  for(auto& p: std::filesystem::directory_iterator(path)){
    if(p.is_directory()) files.push(std::pair<char, std::string>('d', p.path().filename().string() + "/"));
    else files.push(std::pair<char, std::string>('f', p.path().filename().string()));
  };
};
