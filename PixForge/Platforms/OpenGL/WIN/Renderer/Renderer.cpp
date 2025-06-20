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

void PF::PLATFORMS::Renderer::pullEvents(STL::Vector<PF::ENGINE::EventsCodes> &events) {
    glfwPollEvents();
    if (glfwWindowShouldClose(window)) events.push(PF::ENGINE::EventsCodes::Quit);
};

void PF::PLATFORMS::Renderer::proccessEvent(const PF::ENGINE::EventsCodes event) {
    if(event == PF::ENGINE::EventsCodes::Quit) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        running = false;
    }
};
