#define _CRT_SECURE_NO_WARINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"
#include "RenderableObject.h"
#include "NonRenderableObject.h"
#include "Sphere.h"

int main()
{
	FileManager* filemgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();

	RenderableObject* cube = new RenderableObject();
	renderer->addObject(cube);

	filemgr->loadObJ(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"20161676_vs.shader",
		"20161676_fs.shader"
	);

	//cube는 RenderableObject 에서 관리하기때문에 filemgr를 통해 가져와줘야함.

	Sphere* sphere = new Sphere(filemgr);
	renderer->addObject(sphere);

	//sphere는 sphere 자체에서 모든것을 관리함.

	RenderableObject* cube1 = new RenderableObject();
	renderer->addObject(cube1);

	filemgr->loadObJ(
		cube1,
		"cube.obj",
		"uvtemplate.DDS",
		"20161676_vs.shader",
		"20161676_fs.shader"
	);

	Sphere* sphere1 = new Sphere(filemgr);
	renderer->addObject(sphere1);

	sphere->setPosition(-2.0f, 2.0f, 0.0f);
	sphere1->setPosition(2.0f, -2.0f, 0.0f);
	cube->setPosition(2.0f, 2.0f, 0.0f);
	cube1->setPosition(-2.0f, -2.0f, 0.0f);

	NonRenderableObject* non_render_obj = new NonRenderableObject();

	while (true)
	{
		renderer->Clear();

		renderer->render();

		//renderer->computeMatricesFromInputs();

		renderer->update(non_render_obj);

		renderer->Out();
	}
	cube->shutDown();
	sphere->shutDown();
	renderer->shutDown();

	delete cube;
	delete sphere;
	delete non_render_obj;

	return 0;
}