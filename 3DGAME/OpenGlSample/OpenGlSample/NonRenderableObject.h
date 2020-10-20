#ifndef __NONRENDERABLEOBJECT_H__
#define __NONRENDERABLEOBJECT_H__

#include "Object.h"
#include "IUpdate.h"

class NonRenderableObject : public Object, public IUpdate
{
public:
	virtual void shutDown() override;
	virtual void update() override;
};

#endif // !__NONRENDERABLEOBJECT_H__