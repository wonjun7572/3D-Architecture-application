#include "Sun.h"
#include "FileManager.h"
#include "KeyInput.h"

void Sun::setPosition(float x, float y, float z)
{
	Position = glm::vec3(x, y, z);
}

void Sun::init()
{
	FileManager* filemgr = FileManager::instance();

	filemgr->loadObj(
		this,
		"sphere.obj",
		"sun.bmp",
		"20161676_vs.shader",
		"20161676_fs.shader"
	);

	this->setPosition(0, 0, 0);
}

void Sun::render()
{
	glUseProgram(this->programID);

	KeyInput* keyinput = KeyInput::instance();

	keyinput->computeMatricesFromInputs();

	glm::mat4 ProjectionMatrix = keyinput->getProjectionMatrix();
	glm::mat4 ViewMatrix = keyinput->getViewMatrix();
	glm::mat4 ModelMatrix = glm::mat4(1.0);

	glm::mat4 moveObjPos = glm::mat4(1.0f);
	moveObjPos = glm::translate(moveObjPos, this->Position);

	glm::mat4 moveCameraPos = glm::mat4(1.0f);
	moveCameraPos = glm::translate(moveCameraPos, this->cameraPos);

	glm::mat4 MVP = ProjectionMatrix * moveCameraPos * ViewMatrix * moveObjPos * ModelMatrix;

	glUniformMatrix4fv(this->MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->Texture);
	glUniform1i(this->TextureID, 0);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
	glVertexAttribPointer(
		0,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		(void*)0
	);


	// 2nd attribute buffer : UVs
	glBindBuffer(GL_ARRAY_BUFFER, this->uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		2,                                // size : U+V => 2
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	// 3rd attribute buffer : normals
	glBindBuffer(GL_ARRAY_BUFFER, this->normalbuffer);
	glVertexAttribPointer(
		2,                                // attribute
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);



	glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

void Sun::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(MatrixID);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void Sun::update()
{

}
