#include "Renderer.h"

void PF::PLATFORMS::Renderer::createWindow(const std::string &title, const std::string &path){
    window_settings.setPath(path);
    if (!glfwInit()){
        running = false;
        return;
    };
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(800, 600, title.c_str(), nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        running = false;
        return;
    };
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        running = false;
        return;
    };
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
};

void PF::PLATFORMS::Renderer::createBox(){
    const float quadVertices[] = {
        0.0f, 0.0f,
        1.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 0.0f,
        1.0f, 1.0f,
        0.0f, 1.0f
    };
    glGenVertexArrays(1, &boxVAO);
    glGenBuffers(1, &boxVBO);
    glBindVertexArray(boxVAO);
    glBindBuffer(GL_ARRAY_BUFFER, boxVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glBindVertexArray(0);
};

PF::PLATFORMS::Renderer::~Renderer() {
    glfwDestroyWindow(window);
};

void PF::PLATFORMS::Renderer::createRenderer() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    bindDefaultColourBoxShader();
    createBox();
};

void PF::PLATFORMS::Renderer::pullEvents(STL::Vector<PF::ENGINE::EventsCodes> &events) {
    glfwPollEvents();
    if (glfwWindowShouldClose(window)) events.push(PF::ENGINE::EventsCodes::Quit);
    int new_width, new_height;
    glfwGetFramebufferSize(window, &new_width, &new_height);
    if (new_height != height || new_width != width) { events.push(PF::ENGINE::EventsCodes::WindowResize); };
};

void PF::PLATFORMS::Renderer::proccessEvent(const PF::ENGINE::EventsCodes event) {
    if(event == PF::ENGINE::EventsCodes::Quit) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        running = false;
    }
    else if(event == PF::ENGINE::EventsCodes::WindowResize){
        int new_width, new_height;
        glfwGetFramebufferSize(window, &new_width, &new_height);
        width = new_width;
        height = new_height;
        glViewport(0, 0, width, height);
    }
};

void PF::PLATFORMS::Renderer::render(){ glfwSwapBuffers(window);  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); };

void PF::PLATFORMS::Renderer::renderBackground(STL::Vec<float, 4> colour){
  glClearColor(colour[0]/255, colour[1]/255, colour[2]/255, colour[3]/255);
};

void PF::PLATFORMS::Renderer::renderColourBox(STL::Vec<float, 5> position, STL::Vec<float, 4> colour){
    if (compiledShader == 0 || boxVAO == 0) return;
    glUseProgram(compiledShader);
    float x = position[0] / (width/2) - 1.0f;
    float y = 1.0f - position[1] / (height/2);
    float z = 1.0f - position[2];
    float w = position[3] / (width/2);
    float h = position[4] / (height/2);
    GLint posLoc = glGetUniformLocation(compiledShader, "uPos");
    GLint sizeLoc = glGetUniformLocation(compiledShader, "uSize");
    GLint colorLoc = glGetUniformLocation(compiledShader, "uColor");
    glUniform3f(posLoc, x, y - h, z);
    glUniform2f(sizeLoc, w, h);
    glUniform4f(colorLoc, colour[0]/255, colour[1]/255, colour[2]/255, colour[3]/255);
    glBindVertexArray(boxVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
};

void PF::PLATFORMS::Renderer::renderTexture(){

};

void PF::PLATFORMS::Renderer::bindVertexShader(PF::ENGINE::Shader shader) { vertexShader = shader; }
void PF::PLATFORMS::Renderer::bindFragmentShader(PF::ENGINE::Shader shader) { fragmentShader = shader; }

void PF::PLATFORMS::Renderer::bindDefaultColourBoxShader(){
    bindDefaultColourBoxVertexShader();
    bindDefaultColourBoxFragmentShader();
    compileShader();
};
void PF::PLATFORMS::Renderer::bindDefaultTextureShader() {

};
void PF::PLATFORMS::Renderer::bindDefaultColourBoxVertexShader() { vertexShader = PF::ENGINE::Shader(defaultColourBoxVertexShader, ""); };
void PF::PLATFORMS::Renderer::bindDefaultColourBoxFragmentShader() { fragmentShader = PF::ENGINE::Shader(defaultColourBoxFragmentShader, ""); };

void PF::PLATFORMS::Renderer::compileShader() {
    GLuint vertexShaderPart = glCreateShader(GL_VERTEX_SHADER);
    const char* vertexShaderData = vertexShader.getData();
    glShaderSource(vertexShaderPart, 1, &vertexShaderData, nullptr);
    glCompileShader(vertexShaderPart);
    GLuint fragmentShaderPart = glCreateShader(GL_FRAGMENT_SHADER);
    const char* fragmentShaderData = fragmentShader.getData();
    glShaderSource(fragmentShaderPart, 1, &fragmentShaderData, nullptr);
    glCompileShader(fragmentShaderPart);
    compiledShader = glCreateProgram();
    glAttachShader(compiledShader, vertexShaderPart);
    glAttachShader(compiledShader, fragmentShaderPart);
    glLinkProgram(compiledShader);
    glDeleteShader(vertexShaderPart);
    glDeleteShader(fragmentShaderPart);
};
