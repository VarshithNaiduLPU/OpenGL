#include "Application/App.h"
#include "./Inputs.h"

int main()
{
    App app;

    app.CreateGLFWWindow(800, 600, "🔺");

    Inputs::RegisterInputs(app);

    app.BackgroundColor = vec3(0.1f, 0.1f, 0.1f);

    app.AddShader("./Shaders/vertex.glsl", GL_VERTEX_SHADER);
    app.AddShader("./Shaders/fragment.glsl", GL_FRAGMENT_SHADER);
    app.LinkProgram();

    std::vector<GLfloat> vertices1 = {
         0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f
    };

    std::vector<GLfloat> vertices2 = {
         0.5f, -0.5f, 0.0f,    1.0f, 0.0f, 0.0f,
         0.5f,  0.5f, 0.0f,    1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f
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
