#include "App.h"

App::App()
{
    glfw_init();
}

App::~App()
{
    if(shader_program != NULL)
        glDeleteProgram(shader_program);

    glfwTerminate();
}

void App::glfw_init()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void App::CreateGLFWWindow()
{
    window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
    }

    make_program();
}

void App::CreateGLFWWindow(int width, int height)
{
    window = glfwCreateWindow(width, height, "OpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
    }

    make_program();
}

void App::CreateGLFWWindow(int width, int height, std::string title)
{
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
    }

    make_program();
}

void App::Run()
{
     while (!glfwWindowShouldClose(window))
    {
        glClearColor(BackgroundColor.x, BackgroundColor.y, BackgroundColor.z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        all_inputs();
        viewport_size();

        glUseProgram(shader_program);

        glBindVertexArray(temp_vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void App::CloseWindow()
{
    glfwSetWindowShouldClose(window, true);
}

void App::ProcessInputKD(unsigned key, std::function<void()> func)
{
    kdKeys[key].push_back([this, key, func]()
    {
        if (glfwGetKey(window, key) == GLFW_PRESS)
        {
            func();
        }
    });
}

void App::ProcessInput(unsigned key, std::function<void()> func)
{
    keys[key].push_back({func, false});
}

void App::ProcessInputKD(unsigned int key, std::function<void()> func, std::initializer_list<unsigned int> holdKeys)
{

    kdKeys[key].push_back([this, holdKeys, key, func]()
    {
        bool allPressed = true;
        for (const unsigned int &holdKey : holdKeys)
        {
            if (glfwGetKey(window, holdKey) != GLFW_PRESS)
            {
                allPressed = false;
                return;
            }
        }
        if (glfwGetKey(window, key) == GLFW_PRESS)
        {
            func();
        }
    });
}

void App::all_inputs()
{
    for (auto &key : kdKeys)
    {
        for(auto &function : key.second)
            function();
    }

    for (auto &key : keys)
    {
        for(auto &pair : key.second)
        {
            auto &[action, pressed] = pair;

            if (glfwGetKey(window, key.first) == GLFW_PRESS && !pressed)
            {
                action();
                pressed = true;
            }
            else if (glfwGetKey(window, key.first) == GLFW_RELEASE)
            {
                pressed = false;
            }
        }
    }
}

void App::viewport_size()
{
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
}

int App::GetPolygonMode()
{
    GLint mode[2];
    glGetIntegerv(GL_POLYGON_MODE, mode);
    return mode[1];
}

void App::SetPolygonMode(int mode)
{
    glPolygonMode(GL_FRONT_AND_BACK, mode);
}

void App::SetPointSize(float size)
{
    glPointSize(size);
}

void App::SetWindowTitle(std::string title)
{
    glfwSetWindowTitle(window, title.c_str());
}

void App::make_program()
{
    shader_program = glCreateProgram();
}

void App::AddShader(const std::string shaderLocation, GLenum shaderType)
{
    unsigned int shader = glCreateShader(shaderType);
    if(shaderType == GL_VERTEX_SHADER)
        vertex_shader = shader;
    else if(shaderType == GL_FRAGMENT_SHADER)
        fragment_shader = shader;

    std::string ShaderStream;
    std::ifstream shaderFile(shaderLocation);
    if(shaderFile.is_open())
    {
        std::stringstream sstream;
        sstream << shaderFile.rdbuf();
        ShaderStream = sstream.str();
        shaderFile.close();
    }
    else
    {
        std::cout << "Unable to open shader file" << std::endl;
        return;
    }

    const char* ShaderCode = ShaderStream.c_str();

    glShaderSource(shader, 1, &ShaderCode, NULL);
    glCompileShader(shader);

    glAttachShader(shader_program, shader);
}

void App::LinkProgram()
{
    glLinkProgram(shader_program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void App::tempVAO(unsigned int VAO)
{
    temp_vao = VAO;
}
