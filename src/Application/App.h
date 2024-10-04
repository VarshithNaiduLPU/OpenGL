#pragma once

#include "../Headers.h"

class App
{
private:
    GLFWwindow *window;

    unsigned int shader_program = NULL, vertex_shader = NULL, fragment_shader = NULL;

    unsigned int temp_vao = NULL;

    std::unordered_map<unsigned int, std::vector<std::pair<std::function<void()>, bool>>> keys;
    std::unordered_map<unsigned int, std::vector<std::function<void()>>> kdKeys;

    void glfw_init();
    void all_inputs();
    void viewport_size();

    void make_program();

public:
    vec3 BackgroundColor = vec3(0.0f, 0.0f, 0.0f);

    int POINT_MODE = GL_POINT;
    int LINE_MODE = GL_LINE;
    int FILL_MODE = GL_FILL;

    App();
    ~App();

    void CreateGLFWWindow();
    void CreateGLFWWindow(int width, int height);
    void CreateGLFWWindow(int width, int height, std::string title);

    void Run();

    void ProcessInput(unsigned int key, std::function<void()> func);
    void ProcessInputKD(unsigned int key, std::function<void()> func);
    void ProcessInputKD(unsigned int key, std::function<void()> func, std::initializer_list<unsigned int> holdKeys);

    void CloseWindow();

    int GetPolygonMode();
    void SetPolygonMode(int mode);
    void SetPointSize(float size);

    void SetWindowTitle(std::string title);

    void AddShader(const std::string shaderLocation, GLenum shaderType);
    void LinkProgram();

    void tempVAO(unsigned int VAO);
};
