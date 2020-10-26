#ifndef __RENDERABLEOBJECT_H__
#define __RENDERABLEOBJECT_H__

#include "Object.h"
#include "IPosition.h"
#include "IRender.h"

class RenderableObject : public Object, public IRender, public IPosition
{
private:
	bool _IsMoveCheck = false;

public:
	glm::vec3 Position;

	float Position_X;
	float Position_Y;
	float Position_Z;

public:
	virtual void shutDown() override;
	virtual void setPosition(float x, float y, float z) override;

	virtual void setMoving(bool IsCheck);
	virtual bool getMoving();
};

#endif // !__RENDERABLEOBJECT_H__