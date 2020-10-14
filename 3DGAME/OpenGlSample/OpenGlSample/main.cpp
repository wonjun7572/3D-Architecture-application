#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"
#include "RenderableObject.h"
#include "Sphere.h"

GLFWwindow* window;

int main()
{
	FileManager* filemgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();

	RenderableObject* cube = new RenderableObject();
	
	filemgr->loadOBJ(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"20161676_vs.shader",
		"20161676_fs.shader"
		);

	Sphere* sphere = new Sphere();

	glm::mat4 ModelMatrix_Sphere = glm::mat4(1.0);
	ModelMatrix_Sphere = glm::translate(ModelMatrix_Sphere, glm::vec3(3.0f, 0.0f, 0.0f));

	glm::mat4 ModelMatrix_Cube = glm::mat4(1.0);

	while (true)
	{
		renderer->render(sphere, ModelMatrix_Sphere);
		renderer->render(cube, ModelMatrix_Cube);
	}

	cube->shutDown();
	sphere->shutDown();
	renderer->shutDown();
	
	delete cube;

	return 0;
}