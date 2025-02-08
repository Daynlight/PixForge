#include "Gui.h"

PF::Forge::Gui::Gui(const std::string &path, Core::Window *window, Core::Renderer::Objects::Manager* object) 
  :window(window), ui(object, path){
  Tools::Log::log("Gui Created");

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
  Tools::Log::log("ImGui Initialized");

  STL::Folder settings = STL::Folder("settings/");
  if(!settings.exist()) {
    settings.createFolder();
    Tools::Log::war("settings folder Created");
  };

  ui.load();
};

PF::Forge::Gui::~Gui(){
  ui.save();
  ImGui_ImplSDLRenderer2_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();
  Tools::Log::inf("ImGui Destroyed");
  Tools::Log::inf("Gui Destroyed");
};

inline void PF::Forge::Gui::renderDock() {
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

inline void PF::Forge::Gui::renderTopBar(){
  if (ImGui::BeginMainMenuBar()){
    if (ImGui::BeginMenu("Window")){
        if (ImGui::MenuItem("Log")) ui.addWindow(Ui::iUi::Type::LOG);
        if (ImGui::MenuItem("File Explorer [assets]")) ui.addWindow(Ui::iUi::Type::FILE_EXPLORER);
        if (ImGui::MenuItem("Text Editor")) ui.addWindow(Ui::iUi::Type::TEXT_EDITOR);
        if (ImGui::MenuItem("Objects")) ui.addWindow(Ui::iUi::Type::OBJECTS_UI);
        ImGui::EndMenu();
    };
    ImGui::EndMainMenuBar();
  };
};

void PF::Forge::Gui::renderGui(){
  ImGui_ImplSDLRenderer2_NewFrame();
  ImGui_ImplSDL2_NewFrame();
  ImGui::NewFrame();

  renderDock();

  for(size_t i = 0; i < ui.windows.size(); i++) {
    ui.windows[i]->render();
    if(!ui.windows[i]->isOpen()) { delete ui.windows.remove(i); };
  };

  ImGui::Render();
  ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), window->getRenderer());
};

void PF::Forge::Gui::guiEvent(SDL_Event* event){
  ImGui_ImplSDL2_ProcessEvent(event);
};