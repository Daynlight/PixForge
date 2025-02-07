#include "TextEditorUI.h"

void PF::TextEditorUI::render() {
  ImGui::Begin(("Text Editor ("+std::to_string(id)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    ImGui::Text(file.getPath().c_str());
    if(ImGui::Button("exit")) open = false;
    ImGui::EndMenuBar();
  };

  if(ImGui::Button("read")) read();
  ImGui::SameLine();
  if(ImGui::Button("save")){  
    file.clear();
    file.push(text);
    file.save();
  };
  
  ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-1.0f, -1.0f), ImGuiInputTextFlags_AllowTabInput);

  ImGui::End();
};

void PF::TextEditorUI::read(){
  file.clear();
  file.read();
  size_t count = 0;
  for(size_t i = 0; i < file.size(); i++){
    std::string line = file[i];
    for(size_t j = 0; j < line.size(); j++){
      text[count] = line[j];
      count++;
    };
  };
};