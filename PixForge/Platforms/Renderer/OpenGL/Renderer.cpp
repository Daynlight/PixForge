#include "Renderer.h"

void PF::PLATFORM::OpenGLRenderer::createWindow(const std::string &title, int width, int height){
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

void PF::PLATFORM::OpenGLRenderer::createBox(){
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

PF::PLATFORM::OpenGLRenderer::~OpenGLRenderer() {
    glfwDestroyWindow(window);
};

void PF::PLATFORM::OpenGLRenderer::createRenderer() {
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    bindDefaultColourBoxShader();
    createBox();
};

void PF::PLATFORM::OpenGLRenderer::events() {
    if(glfwWindowShouldClose(window)) running = false;
    glfwPollEvents();
};

void PF::PLATFORM::OpenGLRenderer::render(){ 
    glfwSwapBuffers(window);  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
};

PF::ENGINE::Texture* PF::PLATFORM::OpenGLRenderer::renderToTexture() { 
    static GLuint gameTxt = 0;
    static PF::ENGINE::Texture* textureWrapper = nullptr;

    if (gameTxt == 0) {
        glGenTextures(1, &gameTxt);
        glBindTexture(GL_TEXTURE_2D, gameTxt);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glBindTexture(GL_TEXTURE_2D, 0);

        // CPU-side wrapper (RGBA8, width=800, height=600)
        textureWrapper = new PF::ENGINE::Texture(800, 600);
    }

    // Copy framebuffer into GPU texture
    glBindTexture(GL_TEXTURE_2D, gameTxt);
    glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 0, 0,
                     textureWrapper->getWidth(),
                     textureWrapper->getHeight(),
                     0);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Read pixels back to CPU memory
    std::vector<unsigned char> pixels(
        textureWrapper->getWidth() * textureWrapper->getHeight() * 4);

    glReadPixels(0, 0,
                 textureWrapper->getWidth(),
                 textureWrapper->getHeight(),
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 pixels.data());

    // Update Texture’s CPU-side buffer
    textureWrapper->setData(pixels.data(), pixels.size());

    return textureWrapper;
}


void PF::PLATFORM::OpenGLRenderer::renderBackground(UTILITIES::Vec<float, 4> colour){
  glClearColor(colour[0]/255, colour[1]/255, colour[2]/255, colour[3]/255);
};

void PF::PLATFORM::OpenGLRenderer::renderColourBox(UTILITIES::Vec<float, 5> position, UTILITIES::Vec<float, 4> colour){
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

void PF::PLATFORM::OpenGLRenderer::renderTexture(){
    
};

void PF::PLATFORM::OpenGLRenderer::bindVertexShader(PF::ENGINE::Shader shader) { vertexShader = shader; }
void PF::PLATFORM::OpenGLRenderer::bindFragmentShader(PF::ENGINE::Shader shader) { fragmentShader = shader; }

void PF::PLATFORM::OpenGLRenderer::bindDefaultColourBoxShader(){
    bindDefaultColourBoxVertexShader();
    bindDefaultColourBoxFragmentShader();
    compileShader();
};
void PF::PLATFORM::OpenGLRenderer::bindDefaultTextureShader() {

};
void PF::PLATFORM::OpenGLRenderer::bindDefaultColourBoxVertexShader() { vertexShader = PF::ENGINE::Shader(defaultColourBoxVertexShader, ""); };
void PF::PLATFORM::OpenGLRenderer::bindDefaultColourBoxFragmentShader() { fragmentShader = PF::ENGINE::Shader(defaultColourBoxFragmentShader, ""); };

void PF::PLATFORM::OpenGLRenderer::compileShader() {
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

extern "C" PF::PLATFORM::iRenderer* CreateRenderer() {
    return new PF::PLATFORM::OpenGLRenderer();
}
