#pragma once
#ifndef NONRENDERABLEOBJECT_H
#define NONRENDERABLEOBJECT_H

#include <vector>

#include "ICleanUp.h"
#include "Object.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Object;

class NonRenderableObject : public Object
{
public:
    virtual void shutDown() override;
};

#endif