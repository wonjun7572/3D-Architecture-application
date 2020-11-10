#ifndef __NONRENDERABLEOBJECT_H__
#define __NONRENDERABLEOBJECT_H__

#include "Object.h"

class NonRenderableObject : public Object
{
public:
	NonRenderableObject();
	virtual void init() override;
	virtual void render() override;
	virtual void update() override;
	virtual void shutDown() override;
};

#endif // !__NONRENDERABLEOBJECT_H__