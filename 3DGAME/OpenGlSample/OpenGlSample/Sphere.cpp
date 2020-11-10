#include "Sphere.h"
#include "FileManager.h"

Sphere::Sphere()
{
	FileManager* filemgr = FileManager::instance();

	programID = filemgr->LoadShaders("20161676_vs.shader", "20161676_fs.shader");

	MatrixID = glGetUniformLocation(programID, "MVP");

	Texture = filemgr->loadBMP("8k_earth.BMP");

	TextureID = glGetUniformLocation(programID, "myTextureSampler");

	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	bool res = filemgr->loadOBJ("orb.obj", vertices, uvs, normals);

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

	Position = glm::vec3(0.0f, 0.0f, 0.0f);
}

void Sphere::setPosition(float x, float y, float z)
{
	Position = glm::vec3(x, y, z);
}

void Sphere::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void Sphere::setMoving(bool IsCheck)
{
	_IsMoveCheck = IsCheck;
}

bool Sphere::getMoving()
{
	return _IsMoveCheck;
}