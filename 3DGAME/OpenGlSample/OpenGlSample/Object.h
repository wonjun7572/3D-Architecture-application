#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "ICleanUp.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Object : public ICleanUp
{
public:
    virtual ~Object() {}

public:
    virtual void shutDown() override;
};
#endif