#include "Inputs.h"

namespace Inputs
{

    void RegisterInputs(App &app)
    {
        app.ProcessInput(GLFW_KEY_ESCAPE, [&]()
                         {
    Logger::msg("Window closed");
    app.CloseWindow(); });

        app.ProcessInput(GLFW_KEY_F1, [&]()
                         { Logger::msg("Polygon Mode : ", app.GetPolygonMode()); });

        app.ProcessInputKD(GLFW_KEY_P, [&]()
                           {
    app.SetWindowTitle("Polygon Mode : POINT");
    app.SetPointSize(5.0f);
    app.SetPolygonMode(app.POINT_MODE); }, {GLFW_KEY_LEFT_CONTROL});

        app.ProcessInputKD(GLFW_KEY_F, [&]()
                           {
    app.SetWindowTitle("Polygon Mode : FILL");
    app.SetPolygonMode(app.FILL_MODE); }, {GLFW_KEY_LEFT_CONTROL});

        app.ProcessInputKD(GLFW_KEY_L, [&]()
                           {
    app.SetWindowTitle("Polygon Mode : LINE");
    app.SetPolygonMode(app.LINE_MODE); }, {GLFW_KEY_LEFT_CONTROL});

        app.ProcessInput(GLFW_KEY_W, [&]()
                         { Logger::msg("W1"); });

        app.ProcessInput(GLFW_KEY_W, [&]()
                         { Logger::msg("W2"); });
    }
}
