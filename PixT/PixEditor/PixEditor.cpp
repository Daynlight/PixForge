#include "PixEditor.h"

void PE::Editor::run() {

  while (window.isRunning()){
    PC::Renderer::background(&window, backgroundColour);
    
    renderGui();
    editorEvent();
    SDL_RenderPresent(window.getRenderer());
  }
}

void PE::Editor::imGuiDock(){
  ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDocking;
  const ImGuiViewport* viewport = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(viewport->WorkPos);
  ImGui::SetNextWindowSize(viewport->WorkSize);
  ImGui::SetNextWindowViewport(viewport->ID);
  window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
  window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

  ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f)); 
  ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
  ImGui::Begin("Window DockSpace", nullptr, window_flags);
  ImGui::PopStyleVar(2);
  ImGui::PopStyleColor();

  ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
  ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);

  ImGui::End();
}

void PE::Editor::renderGui()
{
  ImGui_ImplSDLRenderer2_NewFrame();
  ImGui_ImplSDL2_NewFrame();
  ImGui::NewFrame();

  imGuiDock();

  ImGui::Begin("Window");
    if(ImGui::Button("Build")) buildGame();
    if(ImGui::Button("Run")) runGame();
  ImGui::End();
  
  ImGui::Render();
  ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), window.getRenderer());
}

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

bool PE::Editor::buildGame(){
  #ifdef _WIN32
    std::string buildCommand = "cmd.exe /B /C ..\\PixT\\PixGame\\scripts\\build.bat \""GAME_TITLE"\"";
  #else
    std::string buildCommand = "bash ../PixT/PixGame/scripts/build.sh '"GAME_TITLE"' &";
  #endif
  int result = system(buildCommand.c_str());
  if (result == -1) return false;
  return true;
}

bool PE::Editor::runGame(){
  #ifdef _WIN32
    std::string runCommand = "start /B cmd.exe /C ..\\PixT\\PixGame\\scripts\\run.bat \""GAME_TITLE"\"";
  #else
    std::string runCommand = "bash ../PixT/PixGame/scripts/run.sh '"GAME_TITLE"' &";
  #endif
  system(runCommand.c_str());
  return true;
}
