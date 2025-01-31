#include "Gui.h"

PF::Gui::Gui(Window *window)
  :window(window){
  Log::inf("Gui Created");

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.IniFilename = "settings/imgui.ini";

  ImGui::StyleColorsDark();
 
  ImGui_ImplSDL2_InitForSDLRenderer(window->getWindow(), window->getRenderer());
  ImGui_ImplSDLRenderer2_Init(window->getRenderer());
  Log::inf("ImGui Initialized");

  Folder settings = Folder("settings/");
  if(!settings.exist()) {
    settings.createFolder();
    Log::war("settings folder Created");
  };

  loadGuiWindow();
};

PF::Gui::~Gui(){
  saveGuiWindow();
  Log::inf("gui_window settings Saved");

  ImGui_ImplSDLRenderer2_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();
  Log::inf("ImGui Destroyed");
  Log::inf("Gui Destroyed");
};

inline void PF::Gui::loadGuiWindow(){
  if(!gui_window.isEmpty()){
    gui_window.read();
    for(size_t i = 0; i < gui_window.size(); i++){
      std::string line = gui_window[i];
      char type = line[0];
      char id = line[1];
      if(uint8_t(type)==1) UIs.push(new LogUI(uint8_t(id)));
      if(uint8_t(type)==2) UIs.push(new FileExplorerUI(uint8_t(id), &UIs, Folder("assets/")));
    }
  }
}

inline void PF::Gui::saveGuiWindow(){
  if(gui_window.isEmpty()) {
    gui_window.createFile();
    Log::war("gui_window file Created");
  }
  gui_window.clear();
  for(size_t i = 0; i < UIs.size(); i++) {
      std::string record = "";
      record += (char)UIs[i]->getType();
      record += (char)UIs[i]->getID();
      gui_window.push(record);
    }
  while(UIs.size() != 0) delete UIs.pop();
  
  gui_window.save();
}

inline void PF::Gui::renderDock()
{
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

  ImGuiID docspace_id = ImGui::GetID("MyDockSpace");
  ImGui::DockSpace(docspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);

  renderTopBar();

  ImGui::End();
};

inline void PF::Gui::renderTopBar(){
  if (ImGui::BeginMainMenuBar()){
    if (ImGui::BeginMenu("Window")){
        if (ImGui::MenuItem("Log")) { UIs.push(new LogUI(PF::UI::generateUniqueID(&UIs))); };
        if (ImGui::MenuItem("File Explorer [assets]")) { UIs.push(new FileExplorerUI(PF::UI::generateUniqueID(&UIs), &UIs, Folder("assets/"))); };
        ImGui::EndMenu();
    };

    if(ImGui::Button("Build")) Builder::buildGame();
    if(ImGui::Button("Run")) Builder::runGame();
    ImGui::EndMainMenuBar();
  };
};

void PF::Gui::renderGui(){
  ImGui_ImplSDLRenderer2_NewFrame();
  ImGui_ImplSDL2_NewFrame();
  ImGui::NewFrame();

  renderDock();

  for(size_t i = 0; i < UIs.size(); i++) 
    if(!UIs[i]->render())
      { delete UIs.remove(i); Log::inf("Window Closed");};
  
  ImGui::Render();
  ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), window->getRenderer());
}
void PF::Gui::guiEvent(SDL_Event* event){
  ImGui_ImplSDL2_ProcessEvent(event);
};