#ifndef __RENDERABLEOBJECT_H__
#define __RENDERABLEOBJECT_H__

#include "Object.h"

class RenderableObject : public Object
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
	virtual void setCameraPos(float x, float y, float z) {};

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
};

#endif // !__RENDERABLEOBJECT_H__