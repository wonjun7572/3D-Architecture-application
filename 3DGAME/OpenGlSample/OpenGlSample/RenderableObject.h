#ifndef __RENDERABLEOBJECT_H__
#define __RENDERABLEOBJECT_H__

#include "CompositeObject.h"
#include <vector>
class RenderableObject : public CompositeObject
{
private:
	bool _IsMoveCheck = false;

public:
	RenderableObject();
	virtual void init() override {};
	virtual void render() override {};
	virtual void update() override {};
	virtual void shutDown() override {};
	virtual void setPosition(float x, float y, float z) {};
	virtual void setRotation(float speed, float x, float y, float z) {};
	virtual void setScale(float x, float y, float z) {};
	virtual void setCameraPos(float x, float y, float z) {};

	virtual void AddChild(CompositeObject* addObj)override {};

public:

	glm::vec3 Position;
	glm::vec3 cameraPos;
	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	GLuint Texture;
	GLuint TextureID;
	GLuint MatrixID;
	GLuint programID;
	GLuint VertexArrayID;
	GLuint LightID;
};

#endif // !__RENDERABLEOBJECT_H__