#pragma once
#include "RenderableObject.h"
#include "IUpdate.h"

class Sun :public RenderableObject
{
public:
	virtual void init() override;
	virtual void render() override;
	virtual void shutDown() override;
	virtual void setPosition(float x, float y, float z) override;
	virtual void update() override;
};
