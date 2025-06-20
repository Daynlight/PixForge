#include "Renderer.h"

void PF::PLATFORMS::Renderer::createWindow(const std::string &title) {
    if (!glfwInit()) {
        running = false;
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(800, 600, title.c_str(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        running = false;
        return;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        running = false;
        return;
    }
    glViewport(0, 0, 800, 600);   
};

void PF::PLATFORMS::Renderer::createRenderer() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
};

void PF::PLATFORMS::Renderer::pullEvents(STL::Vector<PF::ENGINE::EventsCodes> &events) {
    glfwPollEvents();
    if (glfwWindowShouldClose(window)) events.push(PF::ENGINE::EventsCodes::Quit);
};

void PF::PLATFORMS::Renderer::proccessEvent(const PF::ENGINE::EventsCodes event) {
    if(event == PF::ENGINE::EventsCodes::Quit) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        running = false;
    };
};

void PF::PLATFORMS::Renderer::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(window);
};

void PF::PLATFORMS::Renderer::renderBackground(STL::Vec<float, 4> colour){
  glClearColor(colour[0]/255, colour[1]/255, colour[2]/255, colour[3]/255);
};

void PF::PLATFORMS::Renderer::renderColourBox(STL::Vec<int, 3> position, STL::Vec<float, 4> colour){
};

void PF::PLATFORMS::Renderer::renderTexture(){

};