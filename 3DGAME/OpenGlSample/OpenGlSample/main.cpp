#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "Sphere.h"

GLFWwindow* window;

int main()
{
	FileManager* filemgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();

	RenderableObject* cube = new RenderableObject();
	NonRenderableObject* non_render_obj = new NonRenderableObject();

	filemgr->loadOBJ(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"20161676_vs.shader",
		"20161676_fs.shader"
		);

	Sphere* sphere = new Sphere();

	while (true)
	{
		renderer->update(sphere);

		renderer->render(sphere);
		renderer->render(cube);
	}

	cube->shutDown();
	sphere->shutDown();
	renderer->shutDown();
	
	delete cube;
	delete sphere;

	return 0;
}