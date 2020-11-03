#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <vector>

#include "ICleanUp.h"

#include "include/GL/glew.h"
#include "glm/glm.hpp"

class Object :public ICleanUp 
{
public:
	virtual ~Object() {}
};

#endif