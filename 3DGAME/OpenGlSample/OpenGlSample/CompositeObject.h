#pragma once

#include "Object.h"
#include <vector>
#include "FileManager.h"

using namespace std;

class CompositeObject : public Object
{
public:
	CompositeObject();
	~CompositeObject();
	virtual void init() override {};
	virtual void render() override {};
	virtual void update() override;
	virtual void shutDown() override {};

	virtual void AddChild(CompositeObject* addObj);
	CompositeObject* Parent;

	glm::mat4 WorldTransform;
	glm::mat4 Transform;
	glm::mat4 WorldView;
	glm::mat4 View;
protected:
	vector<CompositeObject*>* children;

	float rotSpeed;
	glm::mat4 Scale;
	glm::vec3 scaleVec;
	glm::vec3 rotVec;
	glm::mat4 Rot;

	glm::vec3 cameraPos;

	glm::mat4 movePos;

	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix;
	glm::mat4 ModelMatrix;
public:
	glm::vec3 position;
};