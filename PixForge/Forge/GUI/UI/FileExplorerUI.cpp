#include "FileExplorerUI.h"

PF::FileExplorerUI::FileExplorerUI(const uint8_t ID, Vector<UI*> *UIs, Folder folder) : ID(ID), UIs(UIs), folder(folder) { 
  if(!this->folder.exist()) this->folder.createFolder();
  this->folder.fetchList();
}

bool PF::FileExplorerUI::render(){
  ImGui::Begin(("File Explorer ("+std::to_string(ID)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
    if(ImGui::BeginMenuBar()){
    ImGui::Text(folder.getPath().c_str());
    ImGui::SameLine();
    if(ImGui::Button("back")) {
      size_t index = folder.getPath().size() - 1;
      uint8_t count = 0;
      for(size_t i = folder.getPath().size() - 1; i >= 0; i--) {
        if(folder.getPath()[i] == '/') count++;
        if(count == 2) {
          index = i;
          break;
        }
      }
      folder = Folder(folder.getPath().substr(0, index) + "/");
      folder.fetchList();
    };
    if(ImGui::Button("refresh")) folder.fetchList();
    ImGui::SameLine();
    if(ImGui::Button("exit")){
      ImGui::EndMenuBar();
      ImGui::End();
      return 0;
    };
    ImGui::EndMenuBar();
  };

  if(ImGui::Button("new folder")) createFolder = !createFolder;
    if(createFolder){ 
      ImGui::SameLine();    
      ImGui::InputText("##folder", folderName, IM_ARRAYSIZE(folderName));
      ImGui::SameLine();
      if(ImGui::Button("create folder")){
        folder.openFolder(folderName).createFolder();
        folder.fetchList();
        createFolder = false;
        Log::inf("Folder created: "+std::string(folderName) + "/");
      };
      ImGui::NewLine();
    };
    ImGui::SameLine();
    if(ImGui::Button("new file")) createFile = !createFile;
    if(createFile){   
      ImGui::SameLine();   
      ImGui::InputText("##file", fileName, IM_ARRAYSIZE(fileName));
      ImGui::SameLine();
      if(ImGui::Button("create file")){
        folder.openFile(fileName).createFile();
        folder.fetchList();
        createFile = false;
        Log::inf("File created: "+std::string(fileName));
      };
    };

  ImGui::Text("Files:");
  ImGui::Separator();
  for(size_t i = 0; i < folder.files.size(); i++) {
    if(folder.files[i].first == 'd'){
      if(ImGui::Button((folder.files[i].second + "/").c_str())) 
        folder = Folder(folder.getPath() + folder.files[i].second + "/");
        folder.fetchList();
      }
    else if(ImGui::Button(folder.files[i].second.c_str()))
      UIs->push(new TextEditorUI(generateUniqueID(UIs), folder.getPath() + folder.files[i].second));
    ImGui::SameLine();
    if(ImGui::Button(std::string("delete "+folder.files[i].second).c_str())){
      folder.remove(folder.getPath() + folder.files[i].second);
      folder.fetchList();
      Log::inf("File deleted: "+std::string(folder.getPath() + folder.files[i].second));
    };
  };
  ImGui::End();
  return true;
};