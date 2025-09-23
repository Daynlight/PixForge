#include "Renderer.h"

void PF::FORGE::Renderer::createWindow(const std::string &title, int width, int height){
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

void PF::FORGE::Renderer::createBox(){
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

PF::FORGE::Renderer::~Renderer() {
    glfwDestroyWindow(window);
    glfwTerminate();
};

void PF::FORGE::Renderer::createRenderer() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    bindDefaultColourBoxShader();
    createBox();
};

void PF::FORGE::Renderer::events() {
    if(glfwWindowShouldClose(window)) running = false;
    glfwPollEvents();
};

void PF::FORGE::Renderer::render(){ 
    glfwSwapBuffers(window);  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
};

void PF::FORGE::Renderer::renderBackground(UTILITIES::Vec<float, 4> colour){
  glClearColor(colour[0]/255, colour[1]/255, colour[2]/255, colour[3]/255);
};

void PF::FORGE::Renderer::renderColourBox(UTILITIES::Vec<float, 5> position, UTILITIES::Vec<float, 4> colour){
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

void PF::FORGE::Renderer::renderTexture(){
    
};

void PF::FORGE::Renderer::bindVertexShader(PF::ENGINE::Shader shader) { vertexShader = shader; }
void PF::FORGE::Renderer::bindFragmentShader(PF::ENGINE::Shader shader) { fragmentShader = shader; }

void PF::FORGE::Renderer::bindDefaultColourBoxShader(){
    bindDefaultColourBoxVertexShader();
    bindDefaultColourBoxFragmentShader();
    compileShader();
};
void PF::FORGE::Renderer::bindDefaultTextureShader() {

};
void PF::FORGE::Renderer::bindDefaultColourBoxVertexShader() { vertexShader = PF::ENGINE::Shader(defaultColourBoxVertexShader, ""); };
void PF::FORGE::Renderer::bindDefaultColourBoxFragmentShader() { fragmentShader = PF::ENGINE::Shader(defaultColourBoxFragmentShader, ""); };

void PF::FORGE::Renderer::compileShader() {
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
