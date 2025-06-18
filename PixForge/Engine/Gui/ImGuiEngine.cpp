#include "ImGuiEngine.h"

PF::Engine::ImGuiEngine::ImGuiEngine(const std::string &path, CoreForge::Window* window)
  : window(window) {
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
};

PF::Engine::ImGuiEngine::~ImGuiEngine(){
  ImGui_ImplSDLRenderer2_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();
};

void PF::Engine::ImGuiEngine::dock(std::function<void()> func){
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

void PF::Engine::ImGuiEngine::topBar(std::function<void()> func) {
  if (ImGui::BeginMainMenuBar()){
    if (ImGui::BeginMenu("Window")){
        func();
        ImGui::EndMenu();
    };
    ImGui::EndMainMenuBar();
  };
};

void PF::Engine::ImGuiEngine::events(SDL_Event event){
  ImGui_ImplSDL2_ProcessEvent(&event);
};

void PF::Engine::ImGuiEngine::render(std::function<void()> func) {
  ImGui_ImplSDLRenderer2_NewFrame();
  ImGui_ImplSDL2_NewFrame();
  ImGui::NewFrame();

  func();

  ImGui::Render();
  ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), window->getRenderer());
};
