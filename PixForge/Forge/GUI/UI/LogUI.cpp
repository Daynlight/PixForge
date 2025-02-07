#include "LogUI.h"

void PF::LogUI::render() {
  ImGui::Begin(("Logs ("+std::to_string(ID)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    if(ImGui::Button("exit")) open = false;
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
};
