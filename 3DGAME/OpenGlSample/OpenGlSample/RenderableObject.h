#ifndef __RENDERABLEOBJECT_H__
#define __RENDERABLEOBJECT_H__
//midterm test
#include "Object.h"
#include "IPosition.h"
#include "IRender.h"

class RenderableObject : public Object, public IRender, public IPosition
{
private:
	bool _IsMoveCheck = false;
	bool _IsMoveCheck_WASD = false;

public:
	glm::vec3 Position;

	float Position_X;
	float Position_Y;
	float Position_Z;

public:
	virtual void shutDown() override;
	virtual void setPosition(float x, float y, float z) override;

	virtual void setMoving(bool IsCheck);
	virtual void setMoving_WASD(bool IsCheck);
	virtual bool getMoving();
	virtual bool getMoving_WASD();
};

#endif // !__RENDERABLEOBJECT_H__