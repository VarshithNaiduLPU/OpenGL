#pragma once
#include "../../Headers.h"

inline glm::vec1 vec1(float x)
{
    return glm::vec1(x);
}

#define vec1 glm::vec1

inline glm::vec2 vec2(float x, float y)
{
    return glm::vec2(x, y);
}

#define vec2 glm::vec2

inline glm::vec3 vec3(float x, float y, float z)
{
    return glm::vec3(x, y, z);
}

#define vec3 glm::vec3

inline glm::vec4 vec4(float x, float y, float z, float w)
{
    return glm::vec4(x, y, z, w);
}

#define vec4 glm::vec4
