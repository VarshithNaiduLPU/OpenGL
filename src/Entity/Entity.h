#pragma once

#include "../Headers.h"

class Entity
{
private:
    unsigned int VAO, VBO;
    GLfloat mesh[];
public:
    Entity();
    ~Entity();

    void Draw();
};
