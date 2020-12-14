#pragma once
#include "RenderableObject.h"

class BackGround :public RenderableObject
{
public:
	virtual void setPosition(float x, float y, float z) override;
	virtual void setRotation(float speed, float x, float y, float z)override;
	virtual void setScale(float x, float y, float z)override;
	virtual void setCameraPos(float x, float y, float z) override;
	virtual void init() override;
	virtual void render() override;
	virtual void update() override;
	virtual void shutDown() override;

	virtual void AddChild(CompositeObject* addObj)override;
};