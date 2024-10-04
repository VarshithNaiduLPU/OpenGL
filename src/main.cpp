#include "Application/App.h"

int main()
{
    App app;

    app.CreateGLFWWindow(800, 600, "🌃");
    app.ProcessInput(GLFW_KEY_ESCAPE, [&](){
        Logger::msg("Window closed");
        app.CloseWindow();
    });

    app.ProcessInput(GLFW_KEY_F1, [&](){
        Logger::msg("Polygon Mode : ", app.GetPolygonMode());
    });

    app.ProcessInputKD(GLFW_KEY_P, [&](){
        app.SetWindowTitle("Polygon Mode : POINT");
        app.SetPointSize(10.0f);
        app.SetPolygonMode(app.POINT_MODE);
    }, {GLFW_KEY_LEFT_CONTROL});

    app.ProcessInputKD(GLFW_KEY_F, [&](){
        app.SetWindowTitle("Polygon Mode : FILL");
        app.SetPolygonMode(app.FILL_MODE);
    }, {GLFW_KEY_LEFT_CONTROL});

    app.ProcessInputKD(GLFW_KEY_L, [&](){
        app.SetWindowTitle("Polygon Mode : LINE");
        app.SetPolygonMode(app.LINE_MODE);
    }, {GLFW_KEY_LEFT_CONTROL});



    app.ProcessInput(GLFW_KEY_W, [&](){
        Logger::msg("W1");
    });


    app.ProcessInput(GLFW_KEY_W, [&](){
        Logger::msg("W2");
    });



    app.BackgroundColor = vec3(0.1f, 0.1f, 0.1f);

    app.AddShader("./Shaders/vertex.glsl", GL_VERTEX_SHADER);
    app.AddShader("./Shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    app.LinkProgram();


    std::vector<GLfloat> vertices = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    app.tempVAO(VAO);


    app.Run();

    return 0;
}
