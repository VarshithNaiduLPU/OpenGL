#pragma once

#include "../Headers.h"

class Entity
{
private:
    unsigned int VAO, VBO;
public:
    Entity();
    ~Entity();

    void mesh(std::vector<GLfloat> vertices);
    void Draw();
};
