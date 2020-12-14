#pragma once
#include "RenderableObject.h"

class Reset :public RenderableObject
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

	bool getGameOver();
	void setGameOver(bool _IsGame);

private:
	bool IsGame;
};