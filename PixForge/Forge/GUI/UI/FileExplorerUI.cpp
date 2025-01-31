#include "FileExplorerUI.h"

PF::FileExplorerUI::FileExplorerUI(const uint8_t ID, Vector<UI *> *UIs, Folder folder) : ID(ID), UIs(UIs), folder(folder){
  if(!this->folder.exist()) this->folder.createFolder();
  this->folder.fetchList();
};

inline void PF::FileExplorerUI::popUp(){
  if (ImGui::IsMouseClicked(1)) {
    ImGui::OpenPopup("Options");
  }
  if (ImGui::BeginPopup("Options")) {
    ImGui::Text("Options");
    ImGui::Separator();
    fileManager();
    if (ImGui::Button("Close")) {
      ImGui::CloseCurrentPopup();
    }
    ImGui::EndPopup();
  };
};

inline void PF::FileExplorerUI::fileManager() {
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
  };

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
};

inline void PF::FileExplorerUI::mainMenuBar(){
  if(ImGui::BeginMenuBar()){
  ImGui::Text(folder.getPath().c_str());
  
  ImGui::SameLine();
  if(ImGui::Button("back")) {
    folder = folder.back();
    folder.fetchList();
  };
  
  if(ImGui::Button("refresh")) folder.fetchList();
  ImGui::SameLine();
  if(ImGui::Button("exit")) open = false;
  ImGui::EndMenuBar();
  };
}

inline void PF::FileExplorerUI::renderFolder() {
  ImGui::Text("Files:");
  ImGui::Separator();
  
  for(size_t i = 0; i < folder.files.size(); i++) {
    if(folder.files[i].first == 'd'){
      if(ImGui::Button((folder.files[i].second).c_str())){
        folder = folder.openFolder(folder.files[i].second);
        folder.fetchList();
        break;
      };
    }
    else 
      if(ImGui::Button((folder.files[i].second).c_str()))
        UIs->push(new TextEditorUI(generateUniqueID(UIs), folder.getPath() + folder.files[i].second));

    if (ImGui::BeginPopupContextItem(std::to_string(i).c_str())) {
      if (ImGui::MenuItem("Delete")) {
        Log::inf("File deleted: " + std::string(folder.getPath() + folder.files[i].second));
        folder.remove(folder.files[i].second);
        folder.fetchList();
      }
      ImGui::EndPopup();
    };
  };
};

bool PF::FileExplorerUI::render(){
  ImGui::Begin(("File Explorer ("+std::to_string(ID)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);

  popUp();
  mainMenuBar();
  renderFolder();

  ImGui::End();
  return open;
};