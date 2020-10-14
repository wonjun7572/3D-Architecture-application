#pragma once

#include"RenderableObject.h"
#include "FileManager.h"

class Sphere : public RenderableObject
{
public:
    Sphere();

public:

    GLuint Sphere_VertexArrayID;
    GLuint Sphere_programID;
    GLuint Sphere_MatrixID;
    GLuint Sphere_ViewMatrixID;
    GLuint Sphere_ModelMatrixID;
    GLuint Sphere_Texture;
    GLuint Sphere_TextureID;

    std::vector<glm::vec3> Sphere_vertices;
    std::vector<glm::vec2> Sphere_uvs;
    std::vector<glm::vec3> Sphere_normals;

    GLuint Sphere_vertexbuffer;
    GLuint Sphere_uvbuffer;
    GLuint Sphere_normalbuffer;
    GLuint Sphere_LightID;

private:
    FileManager* Filemgr;

public:
    virtual void shutDown() override;
};