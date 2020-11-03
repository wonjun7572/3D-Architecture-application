#include <stdio.h>

#include "Object.h"
#include "Renderer.h"
#include "RenderableObject.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
//midterm test
void Renderer::init()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "20161676 MidTerm_Test", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Set the mouse at the center of the screen

	glfwSetCursorPos(window, 1024 / 2, 768 / 2);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

}

void Renderer::render()
{
	for (int i = 0; i < objList.size(); i++)
	{
		renderObject(objList[i]);
	}
}

void Renderer::renderObject(RenderableObject* src_obj)
{
	// Use our shader
	glUseProgram(src_obj->programID);

	
	KeyInput::instance()->computeMatricesFromInputs();

	KeyInput::instance()->computeMatricesFromInputs_WASD();

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	// Reset mouse position for next frame
	glfwSetCursorPos(window, 1024 / 2, 768 / 2);

	KeyInput::instance()->horizontalAngle += KeyInput::instance()->mouseSpeed * float(1024 / 2 - xpos);
	KeyInput::instance()->verticalAngle += KeyInput::instance()->mouseSpeed * float(768 / 2 - ypos);

	// Compute the MVP matrix from keyboard and mouse input
	glm::mat4 ProjectionMatrix = KeyInput::instance()->getProjectionMatrix();
	glm::mat4 ViewMatrix = KeyInput::instance()->getViewMatrix();

	glm::mat4 ProjectionMatrix_WASD = KeyInput::instance()->getProjectionMatrix_WASD();
	glm::mat4 ViewMatrix_WASD = KeyInput::instance()->getViewMatrix_WASD();

	glm::mat4 ModelMatrix = glm::mat4(1.0);
	ModelMatrix = getPosition(ModelMatrix, src_obj);

	glUniformMatrix4fv(src_obj->ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
	glUniformMatrix4fv(src_obj->ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);

	float FoV = initialFoV;

	glm::mat4 moveObjPos = glm::mat4(1.0f);
	moveObjPos = glm::translate(moveObjPos, src_obj->Position);

	glm::mat4 moveCameraPos = glm::mat4(1.0f);
	moveCameraPos = glm::translate(moveCameraPos, cameraPos);

	glm::mat4 Projection = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);

	glm::vec3 direction(
		cos(KeyInput::instance()->verticalAngle) * sin(KeyInput::instance()->horizontalAngle),
		sin(KeyInput::instance()->verticalAngle),
		cos(KeyInput::instance()->verticalAngle) * cos(KeyInput::instance()->horizontalAngle)
	);

	glm::vec3 right = glm::vec3(
		sin(KeyInput::instance()->horizontalAngle - 3.14f / 2.0f),
		0,
		cos(KeyInput::instance()->horizontalAngle - 3.14f / 2.0f)
	);

	glm::vec3 position = glm::vec3(0, 0, 5);

	glm::vec3 up = glm::cross(right, direction);

	glm::mat4 View = glm::lookAt(
		position,
		position + direction,
		up
	);

	glm::mat4 To_World = glm::mat4(1.0f);

	glm::mat4 MVP;
	
	if (src_obj->getMoving() == true)
	{
		MVP = ProjectionMatrix * moveCameraPos * ViewMatrix * moveObjPos * ModelMatrix;
	}
	else if (src_obj->getMoving_WASD() == true)
	{
		MVP = ProjectionMatrix_WASD * moveCameraPos * ViewMatrix_WASD * moveObjPos * ModelMatrix;
	}
	else
	{
		MVP = Projection * moveCameraPos * View * moveObjPos * To_World;
	}

	// Camera matrix
	glm::vec3 lightPos = glm::vec3(0, 10, 0);

	glUniform3f(src_obj->LightID, lightPos.x, lightPos.y, lightPos.z);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, src_obj->Texture);
	// Set our "myTextureSampler" sampler to use Texture Unit 0
	glUniform1i(src_obj->TextureID, 0);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, src_obj->vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, src_obj->uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute
		2,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	// 3rd attribute buffer : normals
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, src_obj->normalbuffer);
	glVertexAttribPointer(
		2,                                // attribute
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);

	glDrawArrays(GL_TRIANGLES, 0, src_obj->vertices.size());

	glUniformMatrix4fv(src_obj->MatrixID, 1, GL_FALSE, &MVP[0][0]);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

void Renderer::shutDown()
{
	glfwTerminate();
}

void Renderer::setCameraPos(float x, float y, float z)
{
	cameraPos = glm::vec3(-x, -y, -z);
}

void Renderer::update(IUpdate* src_obj)
{
	src_obj->update();
}

void Renderer::addObject(RenderableObject* render_obj)
{
	objList.push_back(render_obj);
}

glm::mat4 Renderer::getPosition(glm::mat4 Model, RenderableObject* src_obj)
{
	float x, y, z;
	x = src_obj->Position.x;
	y = src_obj->Position.y;
	z = src_obj->Position.z;

	Model = glm::translate(Model, glm::vec3(x, y, z));
	return Model;
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Out()
{
	if (glfwGetKey(GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		exit(0);
	}
	glfwSwapBuffers(window);
	glfwPollEvents();
}