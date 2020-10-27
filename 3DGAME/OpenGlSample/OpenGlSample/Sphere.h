
#ifndef __SPHERE_H__
#define __SPHERE_H__
//midterm test
#include "RenderableObject.h"
#include "FileManager.h"

class Sphere : public RenderableObject
{
private:
	bool _IsMoveCheck = false;

public:
	Sphere(FileManager* filepath);
	virtual void shutDown() override;
	virtual	void setPosition(float x, float y, float z);

	virtual void setMoving(bool IsCheck);
	virtual bool getMoving();
};

#endif // !__SPHERE_H__