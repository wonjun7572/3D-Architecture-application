#ifndef __KEYINPUT_H__
#define __KEYINPUT_H__

#include "include/GL/glew.h"		
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class KeyInput
{
public:

	static KeyInput* instance()
	{
		static KeyInput instance;

		return &instance;
	}

	void computeMatricesFromInputs();

	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;

	glm::mat4 getViewMatrix() {
		return ViewMatrix;
	}

	glm::mat4 getProjectionMatrix() {
		return ProjectionMatrix;
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