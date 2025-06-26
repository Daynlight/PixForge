#include "Renderer.h"

void PF::PLATFORM::Renderer::createWindow(const std::string &title, int width, int height){
    if (!glfwInit()){
        running = false;
        return;
    };
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

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
    glfwGetFramebufferSize(window, &this->width, &this->height);
    glfwGetWindowPos(window, &x, &y);
    glViewport(0, 0, width, height);
};

void PF::PLATFORM::Renderer::createBox(){
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

PF::PLATFORM::Renderer::~Renderer() {
    glfwDestroyWindow(window);
};

void PF::PLATFORM::Renderer::createRenderer() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    bindDefaultColourBoxShader();
    createBox();
};

void PF::PLATFORM::Renderer::pullEventsAndProccessWindowEvents(STL::Vector<PF::ENGINE::EventsCodes> &events) {
    glfwPollEvents();
    if (glfwWindowShouldClose(window)){
        events.push(PF::ENGINE::EventsCodes::Quit);
        glfwSetWindowShouldClose(window, GLFW_TRUE);
        running = false;
    }

    int new_width, new_height;
    glfwGetFramebufferSize(window, &new_width, &new_height);
    if (new_height != height || new_width != width) { 
        events.push(PF::ENGINE::EventsCodes::WindowResize); 
        width = new_width;
        height = new_height;
        glViewport(0, 0, width, height);
    };
    
    int new_x, new_y;
    glfwGetWindowPos(window, &new_x, &new_y);
    if (new_x != x || new_y != y) { 
        events.push(PF::ENGINE::EventsCodes::WindowMove); 
        x = new_x;
        y = new_y;
    };
};

void PF::PLATFORM::Renderer::render(){ glfwSwapBuffers(window);  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); };

void PF::PLATFORM::Renderer::renderBackground(STL::Vec<float, 4> colour){
  glClearColor(colour[0]/255, colour[1]/255, colour[2]/255, colour[3]/255);
};

void PF::PLATFORM::Renderer::renderColourBox(STL::Vec<float, 5> position, STL::Vec<float, 4> colour){
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

void PF::PLATFORM::Renderer::renderTexture(){

};

void PF::PLATFORM::Renderer::bindVertexShader(PF::ENGINE::Shader shader) { vertexShader = shader; }
void PF::PLATFORM::Renderer::bindFragmentShader(PF::ENGINE::Shader shader) { fragmentShader = shader; }

void PF::PLATFORM::Renderer::bindDefaultColourBoxShader(){
    bindDefaultColourBoxVertexShader();
    bindDefaultColourBoxFragmentShader();
    compileShader();
};
void PF::PLATFORM::Renderer::bindDefaultTextureShader() {

};
void PF::PLATFORM::Renderer::bindDefaultColourBoxVertexShader() { vertexShader = PF::ENGINE::Shader(defaultColourBoxVertexShader, ""); };
void PF::PLATFORM::Renderer::bindDefaultColourBoxFragmentShader() { fragmentShader = PF::ENGINE::Shader(defaultColourBoxFragmentShader, ""); };

void PF::PLATFORM::Renderer::compileShader() {
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
