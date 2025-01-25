#include "PixEditor.h"

PE::Editor::Editor(){
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
  //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows

  ImGui::StyleColorsDark();

  ImGui_ImplSDL2_InitForSDLRenderer(window.getWindow(), window.getRenderer());
  ImGui_ImplSDLRenderer2_Init(window.getRenderer());
}

PE::Editor::~Editor(){
    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();

    ImGui::DestroyContext();
}

void PE::Editor::editorEvent(){
  SDL_Event event;
  while(SDL_PollEvent(&event)){
    if(event.type == SDL_KEYDOWN){
      if(event.key.keysym.sym == SDLK_F5) buildGame();
      if(event.key.keysym.sym == SDLK_F6) runGame();
    }

    ImGui_ImplSDL2_ProcessEvent(&event);
    window.windowEvent(event);
  }
}

void PE::Editor::buildGame(){
  #ifdef _WIN32
    std::string buildCommand = "start /B cmd.exe /C ..\\PixT\\PixGame\\scripts\\build.bat \""GAME_TITLE"\"";
  #else
    std::string buildCommand = "bash ../PixT/PixGame/scripts/build.sh '"GAME_TITLE"' &";
  #endif
  system(buildCommand.c_str());
}

void PE::Editor::runGame(){
  #ifdef _WIN32
    std::string runCommand = "start /B cmd.exe /C ..\\PixT\\PixGame\\scripts\\run.bat \""GAME_TITLE"\"";
  #else
    std::string runCommand = "bash ../PixT/PixGame/scripts/run.sh '"GAME_TITLE"' &";
  #endif
  system(runCommand.c_str());
}
