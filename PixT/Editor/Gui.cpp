#include "Gui.h"

void PE::Gui::gui_window_open(uint8_t type){
  bool found = 0;
  int free = -1;
  for(size_t i = 0; i < gui_window.size(); i++) {
      if(free == -1 && gui_window[i].type == 0) free = i;
      if(gui_window[i].type == type) found = 1;
    }
  if(free == -1) Log::war("Too many gui windows");
  if(found == 0 && free >= 0 && free < gui_window.size()) gui_window[free].type = type;
}

PE::Gui::Gui(PC::Window *window)
  :window(window){
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
  //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows

  ImGui::StyleColorsDark();
 
  ImGui_ImplSDL2_InitForSDLRenderer(window->getWindow(), window->getRenderer());
  ImGui_ImplSDLRenderer2_Init(window->getRenderer());

  if(gui_window_file.isEmpty()) gui_window_file.createFile();
  else{
    gui_window_file.read();
    for(size_t i = 0; i < gui_window_file.size(); i++) gui_window[i].type = std::stoi(gui_window_file[i]);
  }
}

PE::Gui::~Gui(){
  if(gui_window_file.isEmpty()) gui_window_file.createFile();
  while (gui_window_file.size() > 0)
    gui_window_file.pop();
  for(size_t i = 0; i < gui_window.size(); i++) if(gui_window[i].type != 0) gui_window_file.push(std::to_string(gui_window[i].type));
  gui_window_file.save();

  ImGui_ImplSDLRenderer2_Shutdown();
  ImGui_ImplSDL2_Shutdown();

  ImGui::DestroyContext();
}

void PE::Gui::imGuiDock(){
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
}


void PE::Gui::renderTopBar()
{
  if (ImGui::BeginMainMenuBar())  // This creates the top menu bar
  {
    if (ImGui::BeginMenu("Window")){
        if (ImGui::MenuItem("Log")) { Log::inf("Log Window Opened"); gui_window_open(1); };
        ImGui::EndMenu();
    }

    if(ImGui::Button("Build")) Builder::buildGame();
    if(ImGui::Button("Run")) Builder::runGame();
    ImGui::EndMainMenuBar();
  }
}

void PE::Gui::renderGui(){
  ImGui_ImplSDLRenderer2_NewFrame();
  ImGui_ImplSDL2_NewFrame();
  ImGui::NewFrame();

  imGuiDock();
  for(size_t i = 0; i < 2; i++) 
    if(gui_window[i].type != 0 && !gui_window[i].render()) 
      { gui_window[i].type = 0; Log::inf("Gui Window closed");};
  
  ImGui::Render();
  ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), window->getRenderer());
}

PE::GuiWindow::GuiWindow(uint8_t type) 
  :type(type){}

bool PE::GuiWindow::render(){
  switch (type){
  case 1:
    return log();
    break;
  }
}

bool PE::GuiWindow::log(){
  ImGui::Begin("Logs");
    for(int i = Log::entry.size() - 1; i >= 0; i--) {
      if(Log::entry[i].first == 0) ImGui::TextColored(ImVec4(200,200,200,255), Log::entry[i].second.c_str());
      if(Log::entry[i].first == 1) ImGui::TextColored(ImVec4(255,255,0,255), Log::entry[i].second.c_str());
      if(Log::entry[i].first == 2) ImGui::TextColored(ImVec4(255,0,0,255), Log::entry[i].second.c_str());
      if(Log::entry[i].first == 3) ImGui::TextColored(ImVec4(0,255,200,255), Log::entry[i].second.c_str());
    }
  ImGui::End();

  return 1;
}
