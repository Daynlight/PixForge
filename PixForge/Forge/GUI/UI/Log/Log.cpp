#include "Log.h"

void PF::Forge::Ui::Log::render() {
  ImGui::Begin(("Logs ("+std::to_string(id)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    if(ImGui::Button("exit")) {open = false; Tools::Log::log("Log UI Window Closed");}
    ImGui::EndMenuBar();
  };
  
  ImGui::Text("Logs:");
  ImGui::Separator();
  for(int i = Tools::Log::size() - 1; i >= 0; i--) {
    if(Tools::Log::at(i).first == 0) ImGui::TextColored(ImVec4(200,200,200,255),Tools::Log::at(i).second.c_str());
    if(Tools::Log::at(i).first == 1) ImGui::TextColored(ImVec4(255,255,0,255),Tools::Log::at(i).second.c_str());
    if(Tools::Log::at(i).first == 2) ImGui::TextColored(ImVec4(255,0,0,255),Tools::Log::at(i).second.c_str());
    if(Tools::Log::at(i).first == 3) ImGui::TextColored(ImVec4(0,255,200,255),Tools::Log::at(i).second.c_str());
  }
  ImGui::End();
};
