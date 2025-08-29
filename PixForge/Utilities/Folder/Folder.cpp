#include "Folder.h"

PF::UTILITIES::Folder PF::UTILITIES::Folder::backFolder() const {
  std::string temp = path;
  temp.pop_back();
  while(temp.size() != 0 && temp.back() != '/') 
    temp.pop_back();
  if(temp.size()) return Folder(temp);
  return Folder(path);
}

std::string PF::UTILITIES::Folder::getPath()
{ return path; };

PF::UTILITIES::Folder::Folder(const std::string &path)
 : path(path) {};

void PF::UTILITIES::Folder::create() {
  std::string temp = ""; 
  for(unsigned int i = 0; i < path.size(); i++){
    if(path[i] == '/'){
      std::filesystem::create_directory(temp);
    }
    temp += path[i];
  };
  std::filesystem::create_directory(path);
}

void PF::UTILITIES::Folder::remove(const std::string &folder) 
{ std::filesystem::remove_all(path + folder); };

const unsigned int PF::UTILITIES::Folder::size() const
{ return data.size(); }

PF::UTILITIES::File PF::UTILITIES::Folder::openFile(const std::string &file)
{ return File(path + file); }

PF::UTILITIES::Folder PF::UTILITIES::Folder::openFolder(const std::string &folder) const
{ return Folder(path + folder); };

const bool PF::UTILITIES::Folder::exist() const
{ return std::filesystem::exists(path); };

void PF::UTILITIES::Folder::fetchList(){
  data.clear(); 
  for(auto& p: std::filesystem::directory_iterator(path)){
    if(p.is_directory()) data.push(std::pair<char, std::string>('d', p.path().filename().string() + "/"));
    else data.push(std::pair<char, std::string>('f', p.path().filename().string()));
  };
};

const std::pair<char, std::string>& PF::UTILITIES::Folder::operator[](const unsigned int &index) const
{ return data[index]; };

std::pair<char, std::string>& PF::UTILITIES::Folder::operator[](const unsigned int &index)
{ return data[index]; };