#include "Application/App.h"

int main()
{
    App app;

    app.CreateGLFWWindow(800, 600, "🔺");


    app.ProcessInput(GLFW_KEY_ESCAPE, [&](){
        Logger::msg("Window closed");
        app.CloseWindow();
    });

    app.ProcessInput(GLFW_KEY_F1, [&](){
        Logger::msg("Polygon Mode : ", app.GetPolygonMode());
    });

    app.ProcessInputKD(GLFW_KEY_P, [&](){
        app.SetWindowTitle("Polygon Mode : POINT");
        app.SetPointSize(5.0f);
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


    std::vector<GLfloat> vertices1 = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.0f, 0.0f
    };

    std::vector<GLfloat> vertices2 = {
        -0.5f,  0.0f, 0.0f,
         0.5f,  0.0f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    Entity entity1;
    entity1.mesh(vertices1);

    app.AddEntity(entity1);

    Entity entity2;
    entity2.mesh(vertices2);

    app.AddEntity(entity2);

    app.Run();

    return 0;
}
