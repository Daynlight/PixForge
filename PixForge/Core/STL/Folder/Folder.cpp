#include "Folder.h"

PF::Folder::Folder(const std::string path) :path(path){}
std::pair<char, std::string> &PF::Folder::operator[](const size_t index){ return files[index]; }
bool PF::Folder::exist() { return std::filesystem::exists(path); };
void PF::Folder::createFolder(){ std::filesystem::create_directory(path); }
PF::File PF::Folder::openFile(const std::string file) { return File(path + "/" + file); }
void PF::Folder::remove(const std::string file) { std::filesystem::remove_all(file); };
void PF::Folder::fetchList() {
  files.clear(); 
  for(auto& p: std::filesystem::directory_iterator(path)){
    if(p.is_directory()) files.push(std::pair<char, std::string>('d', p.path().filename().string()));
    else files.push(std::pair<char, std::string>('f', p.path().filename().string()));
  }
}
PF::Folder PF::Folder::openFolder(const std::string folder) { return Folder(path + "/" + folder); };
std::string PF::Folder::getPath() { return path; }

