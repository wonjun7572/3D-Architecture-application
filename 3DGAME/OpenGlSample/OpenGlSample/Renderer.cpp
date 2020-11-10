#include <stdio.h>

#include "Object.h"
#include "Renderer.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

void Renderer::addRenderObject(RenderableObject* obj)
{
	renderObjList.push_back(obj);
}

void Renderer::addNonRenderObject(NonRenderableObject* obj)
{
	nonrenderObjList.push_back(obj);
}

int Renderer::init()
{
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(1024, 768, "20161676 Choi_Won_Jun", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	glewExperimental = true;

	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// depth test
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	for (std::vector<RenderableObject*>::iterator it = renderObjList.begin(); it != renderObjList.end(); it++)
	{
		(*it)->init();
	}

	for (std::vector<NonRenderableObject*>::iterator it = nonrenderObjList.begin(); it != nonrenderObjList.end(); it++)
	{
		(*it)->init();
	}

}

void Renderer::render()
{
	for (std::vector<RenderableObject*>::iterator it = renderObjList.begin(); it != renderObjList.end(); it++)
	{
		(*it)->render();
	}

	for (std::vector<NonRenderableObject*>::iterator it = nonrenderObjList.begin(); it != nonrenderObjList.end(); it++)
	{
		(*it)->render();
	}
}

void Renderer::shutDown()
{
	glfwTerminate();
	for (std::vector<RenderableObject*>::iterator it = renderObjList.begin(); it != renderObjList.end(); it++)
	{
		(*it)->shutDown();
	}

	for (std::vector<NonRenderableObject*>::iterator it = nonrenderObjList.begin(); it != nonrenderObjList.end(); it++)
	{
		(*it)->shutDown();
	}
}

void Renderer::update()
{
	for (std::vector<RenderableObject*>::iterator it = renderObjList.begin(); it != renderObjList.end(); it++)
	{
		(*it)->update();
	}

	for (std::vector<NonRenderableObject*>::iterator it = nonrenderObjList.begin(); it != nonrenderObjList.end(); it++)
	{
		(*it)->update();
	}
}


void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Out()
{
	if (glfwGetKey(window , GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		exit(0);
	}
	glfwSwapBuffers(window);
	glfwPollEvents();
}