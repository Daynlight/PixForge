#include "Folder.h"

PF::STL::Folder PF::STL::Folder::back(){
  std::string temp = path;
  temp.pop_back();
  while(temp.size() != 0 && temp.back() != '/') 
    temp.pop_back();
  if(temp.size()) return Folder(temp);
  return Folder(path);
};

void PF::STL::Folder::fetchList() {
  files.clear(); 
  for(auto& p: std::filesystem::directory_iterator(path)){
    if(p.is_directory()) files.push(std::pair<char, std::string>('d', p.path().filename().string() + "/"));
    else files.push(std::pair<char, std::string>('f', p.path().filename().string()));
  };
};
