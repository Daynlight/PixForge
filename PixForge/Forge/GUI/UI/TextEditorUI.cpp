#include "TextEditorUI.h"

PF::TextEditorUI::TextEditorUI(const uint8_t ID,std::string path) : ID(ID), path(path) { read(); }

bool PF::TextEditorUI::render() {
  ImGui::Begin(("Text Editor ("+std::to_string(ID)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    ImGui::Text(path.c_str());
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

inline void PF::TextEditorUI::read(){
  std::ifstream file(path);
  std::string line;
  std::string temptext = "";
  while(std::getline(file, line)) temptext += line + "\n";
  strcpy(text, temptext.c_str());
  file.close();
};