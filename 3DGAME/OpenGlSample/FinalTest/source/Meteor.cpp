#include "../include/Meteor.h"
#include "FileManager.h"
#include "Time.h"

void Meteor::setPosition(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
}

void Meteor::setRotation(float speed, float x, float y, float z)
{
	rotSpeed = speed;
	rotVec = glm::vec3(x, y, z);
}

void Meteor::setScale(float x, float y, float z)
{
	scaleVec = glm::vec3(x, y, z);
	if (scaleVec.x != 0.0f || scaleVec.y != 0.0f || scaleVec.z != 0.0f)
	{
		Scale = glm::scale(Scale, scaleVec);
	}
}

void Meteor::setCameraPos(float x, float y, float z)
{
	cameraPos = glm::vec3(-x, -y, -z);
}

void Meteor::init()
{
	FileManager* filemgr = FileManager::instance();
	filemgr->loadObj(this, "sphere.obj", "sun.bmp", "20161676_vs.shader", "20161676_fs.shader");
	this->setCameraPos(0, 0, 0);
	this->setScale(0.0f, 0.0f, 0.0f);

	int random = rand() % 2 + 1;
	float randomPos = rand() / (float)RAND_MAX * (90.0f);
	speed = rand() / (float)RAND_MAX * (0.01f) + (0.1f);
	if (random == 1)
	{
		this->setPosition(randomPos, 30.0f, 0);
	}
	else if (random == 2)
	{
		this->setPosition(-(randomPos), 20.0f, 0);
	}
}

void Meteor::render()
{
	glUseProgram(this->programID);

	position.y -= speed;

	if (position.y < -25.0f)
	{
		int random = rand() % 2 + 1;
		float randomPos = rand() / (float)RAND_MAX * (40.0f);
		speed = rand() / (float)RAND_MAX * (0.01f) + (0.1f);
		if (random == 1)
		{
			this->setPosition(randomPos, 60.0f, 0);
		}
		else if (random == 2)
		{
			this->setPosition(-(randomPos), 20.0f, 0);
		}

	}

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



	glm::mat4 moveCameraPos = glm::mat4(1.0f);
	moveCameraPos = glm::translate(moveCameraPos, this->cameraPos);


	ProjectionMatrix = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

	glm::vec3 direction(
		cos(0.0f) * sin(3.14f),
		sin(0.0f),
		cos(0.0f) * cos(3.14f)
	);

	glm::vec3 right = glm::vec3(
		sin(3.14f - 3.14f / 2.0f),
		0,
		cos(3.14f - 3.14f / 2.0f)
	);

	glm::vec3 position = glm::vec3(0, 0, 5);

	glm::vec3 up = glm::cross(right, direction);

	ViewMatrix = glm::lookAt(
		position,
		position + direction,
		up
	);


	ModelMatrix = glm::mat4(1.0f);

	glm::mat4 MVP;

	if (rotSpeed > 0.0f)
	{
		Rot = glm::rotate(Rot, glm::radians(rotSpeed), rotVec);
	}

	movePos = glm::mat4(1.0f);
	movePos = glm::translate(movePos, this->position);
	Transform = Scale * movePos * Rot * ModelMatrix;


	View = ViewMatrix;

	MVP = ProjectionMatrix * moveCameraPos * WorldView * WorldTransform;


	glUniformMatrix4fv(this->MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glDrawArrays(GL_TRIANGLES, 0, this->vertices.size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);

	if (Parent)
	{
		WorldTransform = Parent->WorldTransform * Transform;
		WorldView = Parent->WorldView;
	}
	else
	{
		WorldTransform = Transform;
		WorldView = View;
	}
}

void Meteor::update()
{

}


void Meteor::shutDown()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(MatrixID);
	glDeleteProgram(programID);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void Meteor::AddChild(CompositeObject* addObj)
{
	children->push_back(addObj);
	addObj->Parent = this;
}