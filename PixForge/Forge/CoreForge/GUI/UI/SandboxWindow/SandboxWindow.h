#pragma once
#include "Core.h"
#include "../Ui.h"
#include "Utilities/Log.h"
#include "Sandbox/Sandbox.h" 

#include "imgui/imgui.h"

#include <iostream>

namespace PF::CoreForge::Ui {

class SandboxWindow : public iUi {
private:
  const uint8_t id;
  bool open = true;
  bool show_grid = true;
  bool show_gizmo = false;
  PF::Sandbox* sandbox = nullptr;
  SDL_Texture* currentTexture = nullptr;

public:
  SandboxWindow(uint8_t id, PF::Sandbox* sandbox)
    : id(id), sandbox(sandbox) {
    Utilities::Log::log("Sandbox UI Window Opened");
  }

  uint8_t getID() override { return id; }
  uint8_t getType() override { return Type::SANDBOX; }
  bool isOpen() override { return open; }

  void render() override {
    if (!open || !sandbox) return;

    ImGui::Begin("Sandbox Preview", &open);

    // SDL_Texture* tex = sandbox->getViewportTexture();

    // if (tex) {
    //   Core::Window* target_window = sandbox->getWindow();
    //   if (target_window) {
    //     auto sizeData = target_window->getWindowSizesAndPosition();
    //     ImVec2 size = ImVec2(static_cast<float>(sizeData.w), static_cast<float>(sizeData.h));
    //     // Cast SDL_Texture* to ImTextureID only if ImGui_ImplSDLRenderer is used
    //     ImGui::Image((ImTextureID)tex, size);
    //   }
    // } else {
    //   ImGui::Text("No preview texture available.");
    // }

    ImGui::End();
  }
};

}; // namespace PF::CoreForge::Ui
