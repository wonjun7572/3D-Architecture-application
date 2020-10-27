#include "RenderableObject.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
//midterm test
void RenderableObject::shutDown()
{
	// Cleanup VBO and shader
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void RenderableObject::setPosition(float x, float y, float z)
{
	Position_X = x;
	Position_Y = y;
	Position_Z = z;
}


void RenderableObject::setMoving(bool IsCheck)
{
	_IsMoveCheck = IsCheck;
}

void RenderableObject::setMoving_WASD(bool IsCheck)
{
	_IsMoveCheck_WASD = IsCheck;
}

bool RenderableObject::getMoving()
{
	return _IsMoveCheck;
}

bool RenderableObject::getMoving_WASD()
{
	return _IsMoveCheck_WASD;
}
