#include "Gui.h"

PF::Gui::Gui(Window *window, Folder* assets_folder)
  :window(window), assets_folder(assets_folder){
  Log::inf("Gui Created");

  Folder settings = Folder("settings/");
  if(!settings.exist()) {
    settings.createFolder();
    Log::war("settings folder Created");
  };

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

  if(gui_window.isEmpty()) {
    gui_window.createFile();
    Log::war("gui_window file Created");
  }
  else gui_window.read();
};

PF::Gui::~Gui(){
  if(gui_window.isEmpty()) {
    gui_window.createFile();
    Log::war("gui_window file Created");
  }
  gui_window.save();
  Log::inf("gui_window settings Saved");

  ImGui_ImplSDLRenderer2_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();
  Log::inf("ImGui Destroyed");
  Log::inf("Gui Destroyed");
};

inline void PF::Gui::gui_window_open(uint8_t type){
  bool found = 0;
  int free = -1;
  for(size_t i = 0; i < gui_window.size(); i++) {
    if(free == -1 && gui_window[i] == "0") free = i;
    if(std::stoi(gui_window[i]) == type) found = 1;
  };
  
  if(found == 0){
    if(free >= 0 && free < gui_window.size()) gui_window[free] = std::to_string(type);
    else gui_window.push(std::to_string(type));
    Log::inf("Window Opened"); 
  }
  else{
    Log::war("Window Already is Open");
  };
};


inline void PF::Gui::renderDock(){
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
        if (ImGui::MenuItem("Log")) { gui_window_open(1); };
        if (ImGui::MenuItem("Text Editor")) { gui_window_open(2); };
        if (ImGui::MenuItem("File Explorer")) { gui_window_open(3); };
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

  for(size_t i = 0; i < gui_window.size(); i++) 
    if(gui_window[i] != "0")
      if(!GuiWindow::render(std::stoi(gui_window[i]), assets_folder))
        { gui_window[i] = "0"; Log::inf("Window Closed");};
  
  ImGui::Render();
  ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), window->getRenderer());
}
void PF::Gui::guiEvent(SDL_Event* event){
  ImGui_ImplSDL2_ProcessEvent(event);
};

bool PF::GuiWindow::render(uint8_t type, Folder *folder){
  switch (type){
  case 1:
    return GuiWindow::log();
    break;
  case 2: 
    return GuiWindow::textEditor();
    break;
  case 3:
    return GuiWindow::fileExplorer(folder);
    break;
  };
  return false;
};

inline bool PF::GuiWindow::log(){
  ImGui::Begin("Logs", nullptr, ImGuiWindowFlags_MenuBar);
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

inline bool PF::GuiWindow::textEditor() {
  ImGui::Begin("Text Editor", nullptr, ImGuiWindowFlags_MenuBar);
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

inline bool PF::GuiWindow::fileExplorer(Folder *folder){
  ImGui::Begin("File Explorer", nullptr, ImGuiWindowFlags_MenuBar);
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
