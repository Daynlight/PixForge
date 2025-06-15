#include "TextEditor.h"

void PF::CoreForge::Ui::TextEditor::render() {
  ImGui::Begin(("Text Editor ("+std::to_string(id)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    ImGui::Text(file.getPath().c_str());
    if(ImGui::Button("exit")) { open = false; Utilities::Log::log("Text Editor UI Window Closed: " + file.getPath() );}
    ImGui::EndMenuBar();
  };

  if(ImGui::Button("read")) read();
  ImGui::SameLine();
  if(ImGui::Button("save")){  
    file.clear();
    file.push(text);
    file.save();
    Utilities::Log::inf("File Saved: " + file.getPath());
  };
  
  ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-1.0f, -1.0f), ImGuiInputTextFlags_AllowTabInput);

  ImGui::End();
};

void PF::CoreForge::Ui::TextEditor::read(){
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
  Utilities::Log::inf("File Read: " + file.getPath());
};