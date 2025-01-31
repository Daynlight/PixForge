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

bool PF::TextEditorUI::render()
{
  ImGui::Begin(("Text Editor("+windowID+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    if(ImGui::Button("exit")){
      ImGui::EndMenuBar();
      ImGui::End();
      return 0;
    };
    ImGui::EndMenuBar();
  };

  ImGui::Text("Text Editor:");
  ImGui::Text("Path: ");
  ImGui::SameLine();

  static char path[256] = "";
  bool update = false;
  if (ImGui::InputText("##path", path, sizeof(path))) update = true;
  ImGui::Separator();

  static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
  static char text[1024 * 16] = "";

  if(ImGui::Button("read") || update){  
    std::ifstream file(path);
    std::string line;
    std::string temptext = "";
    while(std::getline(file, line)) temptext += line + "\n";
    strcpy(text, temptext.c_str());
    update = false;
    file.close();
  };
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

PF::FileExplorerUI::FileExplorerUI(Folder *folder) : folder(folder) { }
bool PF::FileExplorerUI::render(){
  ImGui::Begin(("File Explorer("+windowID+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    if(ImGui::Button("refresh")){
      folder->fetchList();
    };
    ImGui::SameLine();
    if(ImGui::Button("exit")){
      ImGui::EndMenuBar();
      ImGui::End();
      return 0;
    };
    ImGui::Text("Path: ");
    ImGui::SameLine();
    static char name[100] = "";
    ImGui::InputText("##path", name, sizeof(name));
    ImGui::SameLine();
    if(ImGui::Button("new")){
      File file = File(folder->getPath() + "/" + name);
      if(file.isEmpty()) file.createFile();
      folder->fetchList();
      Log::inf("File Created");
    };
    ImGui::EndMenuBar();
  };
  
  ImGui::Text("Files:");
  ImGui::Separator();
  for(size_t i = 0; i < folder->files.size(); i++) {
    ImGui::Text((*folder).files[i].c_str());
  }
  ImGui::End();
  return true;
};
