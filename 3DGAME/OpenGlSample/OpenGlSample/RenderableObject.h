#pragma once
#ifndef RENDERABLEOBJECT_H
#define RENDERABLEOBJECT_H

#include <vector>

#include "Object.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Object;

class RenderableObject : public Object, public IRender
{
public:
    GLuint VertexArrayID;
    GLuint programID;
    GLuint MatrixID;
    GLuint ViewMatrixID;
    GLuint ModelMatrixID;
    GLuint Texture;
    GLuint TextureID;

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec2> uvs;
    std::vector<glm::vec3> normals;

    GLuint vertexbuffer;
    GLuint uvbuffer;
    GLuint normalbuffer;
    GLuint LightID;

public:
    virtual void shutDown() override;
    virtual void render() override;
};

#endif