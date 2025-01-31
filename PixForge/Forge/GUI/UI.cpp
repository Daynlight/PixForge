#include "UI.h"

bool PF::LogUI::render()
{
  ImGui::Begin(("Logs("+windowID+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
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

void PF::TextEditorUI::read(){
  std::ifstream file(path);
  std::string line;
  std::string temptext = "";
  while(std::getline(file, line)) temptext += line + "\n";
  strcpy(text, temptext.c_str());
  file.close();
}

PF::TextEditorUI::TextEditorUI(std::string path) : path(path){
  read();
}

bool PF::TextEditorUI::render() {
  ImGui::Begin(("Text Editor("+windowID+") ["+path+"]").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    if(ImGui::Button("exit")){
      ImGui::EndMenuBar();
      ImGui::End();
      return 0;
    };
    ImGui::EndMenuBar();
  };

  static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;

  if(ImGui::Button("read")) read();
  ImGui::SameLine();
  if(ImGui::Button("save")){  
    std::ofstream file(path);
    file << text;
    file.close();
  };
  
  ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-1.0f, -1.0f), flags);

  ImGui::End();
  return 1;
}

PF::FileExplorerUI::FileExplorerUI(Vector<UI*> *UIs, Folder folder) : UIs(UIs), folder(folder) { 
  if(!this->folder.exist()) this->folder.createFolder();
  this->folder.fetchList();
}
bool PF::FileExplorerUI::render(){
  ImGui::Begin(("File Explorer("+windowID+") ["+folder.getPath()+"]").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
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
        UIs->push(new FileExplorerUI(UIs, Folder(folder.getPath() + folder.files[i].second + "/")));
    }
    else if(ImGui::Button(folder.files[i].second.c_str()))
      UIs->push(new TextEditorUI(folder.getPath()+ folder.files[i].second));
  };
  ImGui::End();
  return true;
};
