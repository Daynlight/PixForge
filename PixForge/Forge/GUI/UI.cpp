#include "UI.h"

uint8_t PF::UI::generateUniqueID(Vector<UI*> *UIs){
  uint8_t ID = 0;
  for(size_t i = 0; i < UIs->size(); i++) if((*UIs)[i]->getID() == ID) ID++;
  return ID;
};

bool PF::LogUI::render() {
  ImGui::Begin(("Logs("+std::to_string(ID)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    if(ImGui::Button("exit")){
      ImGui::EndMenuBar();
      ImGui::End();
      return 0;
    };
    ImGui::EndMenuBar();
  };
  
  ImGui::Text("Logs:");
  ImGui::Separator();
  for(int i = Log::entry.size() - 1; i >= 0; i--) {
    if(Log::entry[i].first == 0) ImGui::TextColored(ImVec4(200,200,200,255), Log::entry[i].second.c_str());
    if(Log::entry[i].first == 1) ImGui::TextColored(ImVec4(255,255,0,255), Log::entry[i].second.c_str());
    if(Log::entry[i].first == 2) ImGui::TextColored(ImVec4(255,0,0,255), Log::entry[i].second.c_str());
    if(Log::entry[i].first == 3) ImGui::TextColored(ImVec4(0,255,200,255), Log::entry[i].second.c_str());
  }
  ImGui::End();

  return 1;
};

PF::TextEditorUI::TextEditorUI(const uint8_t ID,std::string path) : ID(ID), path(path) { read(); }
bool PF::TextEditorUI::render() {
  ImGui::Begin(("Text Editor("+std::to_string(ID)+") ["+path+"]").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    if(ImGui::Button("exit")){
      ImGui::EndMenuBar();
      ImGui::End();
      return 0;
    };
    ImGui::EndMenuBar();
  };

  if(ImGui::Button("read")) read();
  ImGui::SameLine();
  if(ImGui::Button("save")){  
    std::ofstream file(path);
    file << text;
    file.close();
  };
  
  ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-1.0f, -1.0f), ImGuiInputTextFlags_AllowTabInput);

  ImGui::End();
  return 1;
};
void PF::TextEditorUI::read(){
  std::ifstream file(path);
  std::string line;
  std::string temptext = "";
  while(std::getline(file, line)) temptext += line + "\n";
  strcpy(text, temptext.c_str());
  file.close();
}

PF::FileExplorerUI::FileExplorerUI(const uint8_t ID, Vector<UI*> *UIs, Folder folder) : ID(ID), UIs(UIs), folder(folder) { 
  if(!this->folder.exist()) this->folder.createFolder();
  this->folder.fetchList();
}
bool PF::FileExplorerUI::render(){
  ImGui::Begin(("File Explorer("+std::to_string(ID)+") ["+folder.getPath()+"]").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
    if(ImGui::BeginMenuBar()){
    if(ImGui::Button("refresh")) folder.fetchList();
    ImGui::SameLine();
    if(ImGui::Button("exit")){
      ImGui::EndMenuBar();
      ImGui::End();
      return 0;
    };
    ImGui::EndMenuBar();
  };

  ImGui::Text("Files:");
  ImGui::Separator();
  for(size_t i = 0; i < folder.files.size(); i++) {
    if(folder.files[i].first == 'd'){
      if(ImGui::Button((folder.files[i].second + "/").c_str())) 
        UIs->push(new FileExplorerUI(generateUniqueID(UIs), UIs, Folder(folder.getPath() + folder.files[i].second + "/")));
    }
    else if(ImGui::Button(folder.files[i].second.c_str()))
      UIs->push(new TextEditorUI(generateUniqueID(UIs), folder.getPath()+ folder.files[i].second));
  };
  ImGui::End();
  return true;
};