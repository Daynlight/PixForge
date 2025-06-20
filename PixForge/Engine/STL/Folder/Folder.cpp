#include "Folder.h"

PF::ENGINE::STL::Folder PF::ENGINE::STL::Folder::backFolder() const {
  std::string temp = path;
  temp.pop_back();
  while(temp.size() != 0 && temp.back() != '/') 
    temp.pop_back();
  if(temp.size()) return Folder(temp);
  return Folder(path);
};

void PF::ENGINE::STL::Folder::create() {
  std::string temp = ""; 
  for(unsigned int i = 0; i < path.size(); i++){
    if(path[i] == '/'){
      std::filesystem::create_directory(temp);
    }
    temp += path[i];
  };
  std::filesystem::create_directory(path);
};

void PF::ENGINE::STL::Folder::fetchList(){
  data.clear(); 
  for(auto& p: std::filesystem::directory_iterator(path)){
    if(p.is_directory()) data.push(std::pair<char, std::string>('d', p.path().filename().string() + "/"));
    else data.push(std::pair<char, std::string>('f', p.path().filename().string()));
  };
};
