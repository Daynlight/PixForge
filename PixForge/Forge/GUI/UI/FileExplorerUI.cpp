#include "FileExplorerUI.h"

PF::FileExplorerUI::FileExplorerUI(const uint8_t ID, Vector<Ui*> *uis, Folder folder) : ID(ID), uis(uis), folder(folder){
  if(!this->folder.exist()) this->folder.createFolder();
  this->folder.fetchList();
};

inline void PF::FileExplorerUI::popUp(){
  if (ImGui::IsMouseClicked(1)) {
    ImGui::OpenPopup("Options");
  };
  if (ImGui::BeginPopup("Options")) {
    ImGui::Text("Options");
    ImGui::Separator();
    fileManager();
    if (ImGui::Button("Close")) {
      ImGui::CloseCurrentPopup();
    };
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
  
  int columns = std::max(1, static_cast<int>(ImGui::GetWindowWidth() / FILE_BOX_WIDTH));
  ImGui::Columns(columns, nullptr, false);

  for(size_t i = 0; i < folder.files.size(); i++) {
    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, FILE_BOX_BORDER_ROUNDING);
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, FILE_BOX_BORDER);
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.1f, 0.1f, 0.1f, 1.0f));

    ImGui::Button((folder.files[i].second).c_str(), ImVec2(FILE_BOX_WIDTH - FILE_BOX_BORDER_ROUNDING, FILE_BOX_WIDTH - FILE_BOX_BORDER_ROUNDING));

    ImGui::PopStyleColor();
    ImGui::PopStyleVar(2);
    
    if (ImGui::IsItemClicked(1)) {
      ImGui::OpenPopup(std::to_string(i).c_str());
    }

    if (ImGui::BeginPopup(std::to_string(i).c_str())) {
      if (ImGui::MenuItem("Delete")) {
        Log::inf("File deleted: " + std::string(folder.getPath() + folder.files[i].second));
        folder.remove(folder.files[i].second);
        folder.fetchList();
      }
      ImGui::EndPopup();
    }

    if (ImGui::IsItemClicked(0)) {
      if(folder.files[i].first == 'd') {
        folder = folder.openFolder(folder.files[i].second);
        folder.fetchList();
        break;
      } else {
        uis->push(new TextEditorUI(generateUniqueID(uis), folder.getPath() + folder.files[i].second));
      }
    }

    ImGui::NextColumn();
  }

  ImGui::Columns(1);
};

void PF::FileExplorerUI::render(){
  ImGui::Begin(("File Explorer ("+std::to_string(ID)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);

  popUp();
  mainMenuBar();
  renderFolder();

  ImGui::End();
};