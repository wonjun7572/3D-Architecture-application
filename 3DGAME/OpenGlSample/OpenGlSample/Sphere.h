
#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "RenderableObject.h"
#include "FileManager.h"

class Sphere : public RenderableObject
{

public:
	Sphere(FileManager* filepath);
	virtual void shutDown() override;
	virtual	void setPosition(float x, float y, float z);
};

#endif // !__SPHERE_H__