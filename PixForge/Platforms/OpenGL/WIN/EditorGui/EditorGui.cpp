#include "EditorGui.h"

PF::PLATFORM::EditorGui::EditorGui(const std::string &path, iRenderer* renderer)
  : renderer(static_cast<Renderer*>(renderer)) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  io.IniFilename = path.c_str();
  ImGui::StyleColorsDark();
  ImGui_ImplGlfw_InitForOpenGL(this->renderer->getWindow(), true);
  ImGui_ImplOpenGL3_Init("#version 330");
};

PF::PLATFORM::EditorGui::~EditorGui(){
  for(int i = 0; i < ui.size(); i++){
    WindowGui* el = ui.pop();
    delete el;
  };
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
};

uint16_t PF::PLATFORM::EditorGui::generateUnique(){
  uint16_t id = ui.size();
  bool unique_id = false;
  while (!unique_id){
    unique_id = true;
    for(int i = 0; i < ui.size(); i++)
      if(id == ui[i]->getId()) {
        unique_id = false;
        id++;
        break;
      };
  };
  return id;
};

void PF::PLATFORM::EditorGui::dock(std::function<void()> func){
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
  
  func();

  ImGui::End();
};

void PF::PLATFORM::EditorGui::topBar() {
  if (ImGui::BeginMainMenuBar()){
    if (ImGui::BeginMenu("Window")){
      if (ImGui::MenuItem("Log")) addWindow(WindowType::LOG);
      if (ImGui::MenuItem("Objects")) addWindow(WindowType::OBJECTS);
      ImGui::EndMenu();
    };
    ImGui::EndMainMenuBar();
  };
};

void PF::PLATFORM::EditorGui::addWindow(WindowType type) {
  if(type == WindowType::LOG) {
    WindowGui* new_window = static_cast<WindowGui*>(new WindowLogGui(generateUnique()));
    ui.push(new_window);
  }
  else if(type == WindowType::OBJECTS){
    WindowGui* new_window = static_cast<WindowGui*>(new WindowObjectGui(generateUnique()));
    ui.push(new_window);
  };
};

void PF::PLATFORM::EditorGui::render() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  topBar();
  dock([&](){
    for(int i = 0; i < ui.size(); i++){
      ui[i]->render();
      if(!ui[i]->isOpen()) ui.remove(i);
    };
  });
  
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
};

void PF::PLATFORM::WindowLogGui::render() {
  ImGui::Begin(("Logs ("+std::to_string(id)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);
  if(ImGui::BeginMenuBar()){
    if(ImGui::Button("exit")) {open = false; Utilities::Log::log("Log UI Window Closed");}
    ImGui::EndMenuBar();
  };
  
  ImGui::Text("Logs:");
  ImGui::Separator();
  for(int i = Utilities::Log::size() - 1; i >= 0; i--) {
    if(Utilities::Log::at(i).first == 0) ImGui::TextColored(ImVec4(200,200,200,255),Utilities::Log::at(i).second.c_str());
    if(Utilities::Log::at(i).first == 1) ImGui::TextColored(ImVec4(255,255,0,255),Utilities::Log::at(i).second.c_str());
    if(Utilities::Log::at(i).first == 2) ImGui::TextColored(ImVec4(255,0,0,255),Utilities::Log::at(i).second.c_str());
    if(Utilities::Log::at(i).first == 3) ImGui::TextColored(ImVec4(0,255,200,255),Utilities::Log::at(i).second.c_str());
  };
  ImGui::End();
};

void PF::PLATFORM::WindowObjectGui::render(){
  ImGui::Begin(("Objects ("+std::to_string(id)+")").c_str(), nullptr, ImGuiWindowFlags_MenuBar);

  if (ImGui::BeginMenuBar()) {
    if (ImGui::Button("exit")) { open = false; Utilities::Log::log("Objects UI Window Closed"); }
    // if (ImGui::Button("Add Object")) { };
    ImGui::EndMenuBar();
  };

  ImGui::Text("Objects:");
  // for (size_t i = 0; i < Core::Renderer::Objects::Manager::size(); i++) {
  //   auto& obj = Core::Renderer::Objects::Manager::at(i);
  //   if (obj.getType() != Core::Renderer::Objects::iObject::Type::COLOUR_BOX) continue;

    // ImGui::Text(obj.getRefName().c_str());
    // if (ImGui::BeginPopupContextItem(("Object" + std::to_string(i)).c_str())) {
      if (ImGui::MenuItem("Delete")) {
        
        Utilities::Log::log("Object Deleted");
      }
      if (ImGui::MenuItem("Properties")) {

        Utilities::Log::log("Object Properties");
      }
      // ImGui::EndPopup();
    // }
  // }

  ImGui::End();
};
