#ifndef __KEYINPUT_H__
#define __KEYINPUT_H__

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
//midterm test
class KeyInput
{
public:

	static KeyInput* instance()
	{
		static KeyInput instance;

		return &instance;
	}

	void computeMatricesFromInputs();

	void computeMatricesFromInputs_WASD();

	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;
	glm::mat4 ViewMatrix_WASD;
	glm::mat4 ProjectionMatrix_WASD;


	glm::mat4 getViewMatrix() {
		return ViewMatrix;
	}

	glm::mat4 getProjectionMatrix() {
		return ProjectionMatrix;
	}

	glm::mat4 getViewMatrix_WASD() {
		return ViewMatrix_WASD;
	}

	glm::mat4 getProjectionMatrix_WASD() {
		return ProjectionMatrix_WASD;
	}

	// Initial position : on +Z
	glm::vec3 position = glm::vec3(0, 0, 5);
	// Initial horizontal angle : toward -Z
	float horizontalAngle = 3.14f;
	// Initial vertical angle : none
	float verticalAngle = 0.0f;
	// Initial Field of View
	float initialFoV = 45.0f;
	float speed = 3.0f; // 3 units / second
	float mouseSpeed = 0.005f;
};
#endif